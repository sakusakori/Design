#pragma once
#include <ctime>
#include "Entity/Vehicle.h"
#include "Entity/ParkingSpot.h"
using namespace std;

class ParkingLevel;

class Ticket {
private:
    Vehicle* vehicle;
    ParkingLevel* level;
    ParkingSpot* spot;
    time_t entryTime;

public:
    Ticket(Vehicle* vehicle, ParkingLevel* level, ParkingSpot* spot)
        : vehicle(vehicle), level(level), spot(spot) {
        entryTime = time(nullptr);
    }

    Vehicle* getVehicle() { return vehicle; }
    ParkingLevel* getLevel() { return level; }
    ParkingSpot* getSpot() { return spot; }
    time_t getEntryTime() { return entryTime; }
};
