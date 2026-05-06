#pragma once
#include <vector>
#include "Floor.h"
#include "ExternalDispatcher.h"
using namespace std;

class Building {
public:
    vector<Floor*> floors;

    Building(int totalFloors, ExternalDispatcher* dispatcher) {
        for (int i = 1; i <= totalFloors; i++) {
            floors.push_back(new Floor(i, dispatcher));
        }
    }

    ~Building() {
        for (Floor* f : floors) {
            delete f;
        }
    }

    Floor* getFloor(int floor) {
        return floors[floor - 1];
    }
};
