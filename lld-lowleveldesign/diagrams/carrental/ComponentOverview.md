# Car Rental System - Component Overview

## High-Level Architecture

```mermaid
graph TB
    subgraph CLIENT["Client (Demo.cpp)"]
        D[Demo - main]
    end

    subgraph SYSTEM["VehicleRentalSystem"]
        VRS[VehicleRentalSystem]
        U1[User]
        U2[User]
    end

    subgraph STORE["Store (Central Coordinator)"]
        ST[Store]
        LOC[Location]
    end

    subgraph PRODUCT["Product Layer"]
        INV[VehicleInventoryManager]
        V1[Vehicle]
        V2[Vehicle]
        DI[DateInterval]
    end

    subgraph RESERVATION["Reservation Layer"]
        RM[ReservationManager]
        RREPO[ReservationRepository]
        RES[Reservation]
    end

    subgraph BILLING["Billing Layer"]
        BM[BillManager]
        BS{BillingStrategy}
        DBS[DailyBillingStrategy]
        BILL[Bill]
    end

    subgraph PAYMENT["Payment Layer"]
        PM[PaymentManager]
        PS{PaymentStrategy}
        UPIS[UPIPaymentStrategy]
        PAY[Payment]
    end

    D --> VRS
    VRS --> ST
    VRS --> U1
    VRS --> U2
    ST --> LOC

    ST --> INV
    ST --> RM
    ST --> BM
    ST --> PM

    INV --> V1
    INV --> V2
    INV --> DI
    INV -.->|reads bookings| RREPO

    RM --> RREPO
    RM -->|reserve/release| INV
    RREPO --> RES

    BM --> BS
    BS --> DBS
    DBS -->|reads cost| INV
    DBS -->|reads dates| RES
    BM --> BILL

    PM --> PS
    PS --> UPIS
    UPIS -->|marks paid| BILL
    PM --> PAY

    style ST fill:#4a9eff,color:#fff
    style BS fill:#ff9f43,color:#fff
    style PS fill:#ff9f43,color:#fff
    style INV fill:#26de81,color:#fff
    style RM fill:#a55eea,color:#fff
```

## Who Owns What

```
VehicleRentalSystem
├── stores: vector<Store*>          (manages all stores)
└── users: vector<User*>            (manages all users)

Store (Central Coordinator)
├── storeLocation: Location
├── inventory: VehicleInventoryManager
│   ├── vehicles: map<vehicleId, Vehicle*>
│   ├── vehicleBookingIds: map<vehicleId, vector<reservationId>>
│   └── vehicleLocks: map<vehicleId, mutex*>     (thread safety)
│
├── reservationManager: ReservationManager
│   └── reservationRepository: ReservationRepository
│       └── reservations: map<reservationId, Reservation*>
│
├── billManager: BillManager
│   ├── billingStrategy: BillingStrategy*         (Strategy Pattern)
│   └── bills: map<billId, Bill*>
│
└── paymentManager: PaymentManager
    ├── paymentStrategy: PaymentStrategy*         (Strategy Pattern)
    └── payments: map<paymentId, Payment*>
```

## Design Patterns Used

| Pattern               | Where                                      | Purpose                                        |
|-----------------------|--------------------------------------------|-------------------------------------------------|
| **Strategy**          | BillingStrategy / PaymentStrategy          | Swap billing & payment algorithms at runtime    |
| **Repository**        | ReservationRepository                      | Abstracts data storage for reservations         |
| **Manager / Service** | ReservationManager, BillManager, PaymentManager | Business logic separated from data objects  |
| **Composition**       | Store owns all managers                    | Store is the central coordinator                |

## Data Flow Summary

```
SEARCH:   Client -> Store -> VehicleInventoryManager -> (checks DateInterval overlaps) -> returns available vehicles

CREATE:   Client -> Store -> ReservationManager -> VehicleInventoryManager.reserve() [with mutex lock]
                                                -> ReservationRepository.save()

TRIP:     Client -> Store -> ReservationManager -> ReservationRepository.findById()
                                                -> reservation.setStatus(IN_USE / COMPLETED)
                                                -> VehicleInventoryManager.release() [with mutex lock]

BILLING:  Client -> Store -> BillManager -> DailyBillingStrategy
                                            -> reads Reservation (dates)
                                            -> reads Vehicle (daily cost)
                                            -> calculates: days * rate
                                            -> returns Bill

PAYMENT:  Client -> Store -> PaymentManager -> UPIPaymentStrategy
                                               -> creates Payment
                                               -> marks Bill as paid
                          -> ReservationManager.remove() (cleanup)
```

## Thread Safety Points

```
VehicleInventoryManager:
  - Per-vehicle mutex lock in reserve()     -> prevents double-booking same vehicle
  - Per-vehicle mutex lock in release()     -> safe concurrent release
  - Per-vehicle mutex lock in hasFreeSpot() -> consistent read

All other classes are single-threaded in the demo,
but the inventory layer is designed for concurrent access.
```
