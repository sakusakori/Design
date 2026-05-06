#pragma once
#include <vector>
#include <stdexcept>
#include "Location.h"
#include "User.h"
#include "product/Vehicle.h"
#include "product/VehicleType.h"
#include "product/VehicleInventoryManager.h"
#include "product/DateInterval.h"
#include "reservation/Reservation.h"
#include "reservation/ReservationManager.h"
#include "reservation/ReservationType.h"
#include "Bill/Bill.h"
#include "Bill/BillManager.h"
#include "Bill/BillingStrategy.h"
#include "Bill/DailyBillingStrategy.h"
#include "payment/Payment.h"
#include "payment/PaymentManager.h"
#include "payment/PaymentStrategy.h"
#include "payment/UPIPaymentStrategy.h"
using namespace std;

class Store {
private:
    int storeId;
    Location storeLocation;
    VehicleInventoryManager inventory;
    ReservationManager reservationManager;

    DailyBillingStrategy defaultBillingStrategy;
    BillManager billManager;

    UPIPaymentStrategy defaultPaymentStrategy;
    PaymentManager paymentManager;

public:
    Store(int storeId, Location location)
        : storeId(storeId), storeLocation(move(location)),
          reservationManager(&inventory),
          defaultBillingStrategy(&inventory),
          billManager(&defaultBillingStrategy),
          paymentManager(&defaultPaymentStrategy) {}

    // ----------------- Search Vehicles --------------------

    vector<Vehicle*> getVehicles(VehicleType type, LocalDate from, LocalDate to) {
        return inventory.getAvailableVehicles(type, from, to);
    }

    // ----------------- Create Reservation -----------------
    Reservation* createReservation(int vehicleId, User* user, LocalDate from, LocalDate to,
                                   ReservationType type) {
        return reservationManager.createReservation(vehicleId, user->getUserId(), from, to, type);
    }

    // ----------------- Update Reservation -----------------

    void cancelReservation(int reservationId) {
        reservationManager.cancelReservation(reservationId);
    }

    void startTrip(int reservationId) {
        reservationManager.startTrip(reservationId);
    }

    void submitVehicle(int reservationId) {
        reservationManager.submitVehicle(reservationId);
    }

    // ----------------- Billing & Payment ------------------

    Bill* generateBill(int reservationId, BillingStrategy* billingStrategy) {
        Reservation* r = reservationManager.findByID(reservationId);
        if (r == nullptr) throw runtime_error("Reservation not found");

        billManager.setBillingStrategy(billingStrategy);
        return billManager.generateBill(r);
    }

    Payment* makePayment(Bill* bill, PaymentStrategy* paymentStrategy, double paymentAmount) {
        paymentManager.setPaymentStrategy(paymentStrategy);
        Payment* payment = paymentManager.makePayment(bill, paymentAmount);

        if (!bill->isBillPaid()) {
            throw runtime_error("Payment failed");
        }

        // NOW we can safely remove the reservation from the repo
        reservationManager.remove(bill->getReservationId());
        return payment;
    }

    VehicleInventoryManager* getInventory() { return &inventory; }
    int getStoreId() { return storeId; }
};
