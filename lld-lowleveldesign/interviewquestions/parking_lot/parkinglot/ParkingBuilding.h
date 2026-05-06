#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include "../Entity/Vehicle.h"
#include "../Entity/ParkingSpot.h"
#include "../Ticket.h"
#include "../pricing/CostComputation.h"
#include "ParkingLevel.h"
using namespace std;

class ParkingBuilding {
private:
    vector<ParkingLevel*> levels;

public:
    ParkingBuilding(vector<ParkingLevel*> levels, CostComputation* costComputation)
        : levels(move(levels)) {}

    Ticket* allocate(Vehicle* vehicle) {
        for (ParkingLevel* level : levels) {
            if (level->hasAvailability(vehicle->getVehicleType())) {
                ParkingSpot* spot = level->park(vehicle->getVehicleType());
                if (spot != nullptr) {
                    Ticket* ticket = new Ticket(vehicle, level, spot);
                    cout << "Parking allocated at level: "
                         << level->getLevelNumber()
                         << " spot: " << spot->getSpotId() << endl;
                    return ticket;
                }
            }
        }
        throw runtime_error("Parking Full");
    }

    void release(Ticket* ticket) {
        ticket->getLevel()->unPark(
            ticket->getVehicle()->getVehicleType(),
            ticket->getSpot()
        );
    }
};
