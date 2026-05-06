# Car Rental System - Sequence Diagram (Complete Flow)

## Flow 1: Search Available Vehicles

```mermaid
sequenceDiagram
    participant Client as Demo (Client)
    participant System as VehicleRentalSystem
    participant S as Store
    participant Inv as VehicleInventoryManager
    participant RRepo as ReservationRepository

    Client->>System: getStore(1001)
    System-->>Client: Store*

    Client->>S: getVehicles(FOUR_WHEELER, fromDate, toDate)
    S->>Inv: getAvailableVehicles(type, from, to)

    loop For each vehicle in inventory
        Inv->>Inv: isAvailable(vehicleId, from, to)
        Note over Inv: Check VehicleStatus != MAINTENANCE
        Inv->>RRepo: findById(reservationId) for each booking
        RRepo-->>Inv: Reservation*
        Note over Inv: Check DateInterval.overlaps()
    end

    Inv-->>S: vector~Vehicle*~ (available ones)
    S-->>Client: vector~Vehicle*~
```

## Flow 2: Create Reservation

```mermaid
sequenceDiagram
    participant Client as Demo (Client)
    participant S as Store
    participant RM as ReservationManager
    participant Inv as VehicleInventoryManager
    participant RRepo as ReservationRepository

    Client->>S: createReservation(vehicleId=1, user, from, to, DAILY)
    S->>RM: createReservation(vehicleId, userId, from, to, DAILY)

    Note over RM: Generate reservationId = 20000

    RM->>Inv: reserve(vehicleId=1, reservationId=20000, from, to)
    Note over Inv: 🔒 Lock per-vehicle mutex

    Inv->>Inv: isAvailable(vehicleId, from, to)
    Note over Inv: Check date overlaps with existing bookings

    alt Vehicle Available
        Inv->>Inv: vehicleBookingIds[1].push_back(20000)
        Inv->>Inv: vehicle.setStatus(BOOKED)
        Inv-->>RM: true
    else Vehicle NOT Available
        Inv-->>RM: false
        RM-->>S: throw runtime_error
    end

    Note over Inv: 🔓 Unlock mutex

    RM->>RM: new Reservation(20000, 1, userId, from, to, DAILY)
    RM->>RRepo: save(reservation)
    RM-->>S: Reservation*
    S-->>Client: Reservation*
```

## Flow 3: Start Trip & Submit Vehicle

```mermaid
sequenceDiagram
    participant Client as Demo (Client)
    participant S as Store
    participant RM as ReservationManager
    participant RRepo as ReservationRepository
    participant Inv as VehicleInventoryManager

    Note over Client: === START TRIP ===
    Client->>S: startTrip(reservationId=20000)
    S->>RM: startTrip(20000)
    RM->>RRepo: findById(20000)
    RRepo-->>RM: Reservation*
    RM->>RM: reservation.setStatus(IN_USE)

    Note over Client: === SUBMIT VEHICLE ===
    Client->>S: submitVehicle(reservationId=20000)
    S->>RM: submitVehicle(20000)
    RM->>RRepo: findById(20000)
    RRepo-->>RM: Reservation*
    RM->>RM: reservation.setStatus(COMPLETED)

    RM->>Inv: release(vehicleId=1, reservationId=20000)
    Note over Inv: 🔒 Lock per-vehicle mutex
    Inv->>Inv: Remove 20000 from vehicleBookingIds[1]
    Inv->>Inv: vehicle.setStatus(AVAILABLE)
    Note over Inv: 🔓 Unlock mutex
```

## Flow 4: Generate Bill

```mermaid
sequenceDiagram
    participant Client as Demo (Client)
    participant S as Store
    participant BM as BillManager
    participant DBS as DailyBillingStrategy
    participant RM as ReservationManager
    participant Inv as VehicleInventoryManager

    Client->>S: generateBill(reservationId=20000, DailyBillingStrategy)
    S->>RM: findByID(20000)
    RM-->>S: Reservation*
    S->>BM: setBillingStrategy(DailyBillingStrategy)
    S->>BM: generateBill(reservation)

    BM->>DBS: generateBill(reservation)

    Note over DBS: days = daysBetween(from, to) + 1 = 3
    DBS->>Inv: getVehicle(vehicleId=1)
    Inv-->>DBS: Vehicle* (dailyRentalCost = 1100)

    Note over DBS: total = 3 * 1100 = 3300
    DBS->>DBS: new Bill(5000, 20000, 3300)
    DBS-->>BM: Bill*

    BM->>BM: bills[5000] = bill (store it)
    BM-->>S: Bill*
    S-->>Client: Bill*
```

## Flow 5: Make Payment

```mermaid
sequenceDiagram
    participant Client as Demo (Client)
    participant S as Store
    participant PM as PaymentManager
    participant UPI as UPIPaymentStrategy
    participant RM as ReservationManager

    Client->>S: makePayment(bill, UPIPaymentStrategy, 3300)
    S->>PM: setPaymentStrategy(UPIPaymentStrategy)
    S->>PM: makePayment(bill, 3300)

    PM->>UPI: processPayment(bill, 3300)
    UPI->>UPI: new Payment(9000, billId=5000, 3300, UPI, now)
    UPI->>UPI: bill.setBillPaid(true)
    UPI-->>PM: Payment*

    PM->>PM: payments[9000] = payment (store it)
    PM-->>S: Payment*

    S->>S: Verify bill.isBillPaid() == true

    Note over S: Cleanup: remove reservation from repo
    S->>RM: remove(reservationId=20000)

    S-->>Client: Payment*

    Note over Client: Print Payment Receipt
```
