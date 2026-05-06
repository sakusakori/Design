#pragma once
#include "ParkingSpotManager.h"

/*
 1. Maintains a list of Two Wheeler Spots only
 2. Has its own lookup strategy
 3. Has its own lock, to avoid conflicts with other spot managers
 */
class TwoWheelerSpotManager : public ParkingSpotManager {
public:
    TwoWheelerSpotManager(vector<ParkingSpot*> spots, ParkingSpotLookupStrategy* strategy)
        : ParkingSpotManager(move(spots), strategy) {}
};
