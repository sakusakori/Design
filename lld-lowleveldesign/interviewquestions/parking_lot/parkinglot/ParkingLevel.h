#pragma once
#include <map>
#include <stdexcept>
#include "../enums/VehicleType.h"
#include "../Entity/ParkingSpot.h"
#include "../spotManagers/ParkingSpotManager.h"
using namespace std;

class ParkingLevel {
private:
    int levelNumber;
    map<VehicleType, ParkingSpotManager*> managers;

public:
    ParkingLevel(int levelNumber, map<VehicleType, ParkingSpotManager*> managers)
        : levelNumber(levelNumber), managers(move(managers)) {}

    bool hasAvailability(VehicleType type) {
        auto it = managers.find(type);
        return it != managers.end() && it->second->hasFreeSpot();
    }

    ParkingSpot* park(VehicleType type) {
        auto it = managers.find(type);
        if (it == managers.end()) {
            throw invalid_argument("No parking manager for vehicle type");
        }
        return it->second->park();
    }

    void unPark(VehicleType type, ParkingSpot* spot) {
        auto it = managers.find(type);
        if (it != managers.end()) {
            it->second->unPark(spot);
        }
    }

    int getLevelNumber() { return levelNumber; }
};
