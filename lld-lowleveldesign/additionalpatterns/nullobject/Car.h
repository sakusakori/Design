#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {
private:
    string model;
    string color;
    int seatingCapacity;
    int fuelTankCapacity;
    bool availableForTestDrive;

public:
    Car(string model, string color, int seatingCapacity, int fuelTankCapacity, bool availableForTestDrive)
        : model(move(model)), color(move(color)), seatingCapacity(seatingCapacity),
          fuelTankCapacity(fuelTankCapacity), availableForTestDrive(availableForTestDrive) {}

    void start() override {
        cout << "Car is started and moving" << endl;
    }

    void stop() override {
        cout << "Car is stopped" << endl;
    }

    // Getters
    string getModel() { return model; }
    string getColor() { return color; }
    int getSeatingCapacity() { return seatingCapacity; }
    int getFuelTankCapacity() { return fuelTankCapacity; }
    bool isAvailableForTestDrive() { return availableForTestDrive; }
};
