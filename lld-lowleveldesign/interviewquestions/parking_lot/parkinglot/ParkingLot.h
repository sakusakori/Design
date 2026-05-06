#pragma once
#include "../Entity/Vehicle.h"
#include "../Ticket.h"
#include "../payment/Payment.h"
#include "ParkingBuilding.h"
#include "EntranceGate.h"
#include "ExitGate.h"

class ParkingLot {
private:
    ParkingBuilding* building;
    EntranceGate* entranceGate;
    ExitGate* exitGate;

public:
    ParkingLot(ParkingBuilding* building, EntranceGate* entranceGate, ExitGate* exitGate)
        : building(building), entranceGate(entranceGate), exitGate(exitGate) {}

    Ticket* vehicleArrives(Vehicle* vehicle) {
        return entranceGate->enter(building, vehicle);
    }

    void vehicleExits(Ticket* ticket, Payment* payment) {
        exitGate->completeExit(building, ticket, payment);
    }
};
