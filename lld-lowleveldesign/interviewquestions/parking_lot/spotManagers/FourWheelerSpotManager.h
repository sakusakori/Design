#pragma once
#include "ParkingSpotManager.h"

/*
 1. Maintains a list of Four Wheeler Spots only
 2. Has its own lookup strategy
 3. Has its own lock, to avoid conflicts with other spot managers
 */
class FourWheelerSpotManager : public ParkingSpotManager {
public:
    FourWheelerSpotManager(vector<ParkingSpot*> spots, ParkingSpotLookupStrategy* strategy)
        : ParkingSpotManager(move(spots), strategy) {}
};
