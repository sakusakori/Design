#pragma once
#include <string>
using namespace std;

class ParkingSpot {
private:
    string spotId;
    bool isFree = true;

public:
    ParkingSpot(string spotId) : spotId(move(spotId)) {}

    bool isSpotFree() {
        return isFree;
    }

    void occupySpot() {
        isFree = false;
    }

    void releaseSpot() {
        isFree = true;
    }

    string getSpotId() {
        return spotId;
    }
};
