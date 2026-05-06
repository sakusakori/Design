#pragma once
#include "BillingStrategy.h"
#include "Bill.h"
#include "../product/VehicleInventoryManager.h"
#include "../reservation/Reservation.h"
using namespace std;

class DailyBillingStrategy : public BillingStrategy {
private:
    VehicleInventoryManager* vehicleInventoryManager;
    int billIdCounter = 5000;

public:
    DailyBillingStrategy(VehicleInventoryManager* vehicleInventoryManager)
        : vehicleInventoryManager(vehicleInventoryManager) {}

    Bill* generateBill(Reservation* reservation) override {

        long days = reservation->getDateBookedFrom()
                        .daysBetween(reservation->getDateBookedTo()) + 1;

        Vehicle* vehicle = vehicleInventoryManager->getVehicle(reservation->getVehicleId());
        double rate = vehicle->getDailyRentalCost();

        double total = days * rate;

        return new Bill(billIdCounter++, reservation->getReservationId(), total);
    }
};
