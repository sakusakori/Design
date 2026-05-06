#pragma once
#include <vector>
#include <mutex>
#include <algorithm>
#include "../Entity/ParkingSpot.h"
#include "../LookupStrategy/ParkingSpotLookupStrategy.h"
using namespace std;

class ParkingSpotManager {
protected:
    vector<ParkingSpot*> spots;
    ParkingSpotLookupStrategy* strategy;
    mutex lock;

    ParkingSpotManager(vector<ParkingSpot*> spots, ParkingSpotLookupStrategy* strategy)
        : spots(move(spots)), strategy(strategy) {}

public:
    virtual ~ParkingSpotManager() = default;

    ParkingSpot* park() {
        lock_guard<mutex> guard(lock);
        ParkingSpot* spot = strategy->selectSpot(spots);
        if (spot == nullptr) {
            return nullptr;
        }
        spot->occupySpot();
        return spot;
    }

    void unPark(ParkingSpot* spot) {
        lock_guard<mutex> guard(lock);
        spot->releaseSpot();
    }

    bool hasFreeSpot() {
        lock_guard<mutex> guard(lock);
        return any_of(spots.begin(), spots.end(),
            [](ParkingSpot* s) { return s->isSpotFree(); });
    }
};
