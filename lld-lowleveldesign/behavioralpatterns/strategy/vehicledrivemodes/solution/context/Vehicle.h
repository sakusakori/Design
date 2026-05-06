#pragma once
#include <iostream>
#include <string>
#include "../strategies/DriveStrategy.h"
using namespace std;

// Context class - holds a reference to a strategy object
class Vehicle {
public:
    DriveStrategy* driveStrategy;

    // constructor injection
    Vehicle(DriveStrategy* driveStrategy) : driveStrategy(driveStrategy) {}
    virtual ~Vehicle() = default;

    virtual void drive() {
        cout << "\nVehicle: ";
        driveStrategy->drive();
    }
};
