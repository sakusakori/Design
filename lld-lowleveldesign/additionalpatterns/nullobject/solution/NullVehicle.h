#pragma once
#include <iostream>
#include <string>
#include "../Vehicle.h"
using namespace std;

class NullVehicle : public Vehicle {
private:
    string model;
    string color;
    int seatingCapacity;
    int fuelTankCapacity;
    bool availableForTestDrive;

public:
    NullVehicle()
        : model("Default"), color("Default"),
          seatingCapacity(0), fuelTankCapacity(0),
          availableForTestDrive(false) {}

    void start() override {
        // Do nothing - silent Vehicle
        cout << "\n[-] Null Vehicle: start() - do nothing";
    }

    void stop() override {
        // Do nothing - silent Vehicle
        cout << "\n[-] Null Vehicle: stop() - do nothing" << endl;
    }

    // Getters
    int getSeatingCapacity() { return seatingCapacity; }
    int getFuelTankCapacity() { return fuelTankCapacity; }
    bool isAvailableForTestDrive() { return availableForTestDrive; }
};
