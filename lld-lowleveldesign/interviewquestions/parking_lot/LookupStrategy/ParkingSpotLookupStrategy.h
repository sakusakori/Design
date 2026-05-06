#pragma once
#include <vector>
#include "../Entity/ParkingSpot.h"
using namespace std;

class ParkingSpotLookupStrategy {
public:
    virtual ~ParkingSpotLookupStrategy() = default;

    virtual ParkingSpot* selectSpot(vector<ParkingSpot*>& spots) = 0;
};
