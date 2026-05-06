#pragma once
#include "ParkingSpotLookupStrategy.h"

class RandomLookupStrategy : public ParkingSpotLookupStrategy {
public:
    ParkingSpot* selectSpot(vector<ParkingSpot*>& spots) override {
        for (ParkingSpot* spot : spots) {
            if (spot->isSpotFree()) {
                return spot;
            }
        }
        return nullptr;
    }
};
