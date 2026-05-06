#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Bike : public Vehicle {
private:
    string model;
    string color;
    int seatingCapacity;
    int fuelTankCapacity;
    bool availableForTestDrive;

public:
    Bike(string model, string color, int fuelTankCapacity)
        : model(move(model)), color(move(color)), fuelTankCapacity(fuelTankCapacity),
          availableForTestDrive(false), seatingCapacity(2) {}

    void start() override {
        cout << "Bike is started and moving" << endl;
    }

    void stop() override {
        cout << "Bike is stopped" << endl;
    }

    // Getters
    string getModel() { return model; }
    string getColor() { return color; }
    int getSeatingCapacity() { return seatingCapacity; }
    int getFuelTankCapacity() { return fuelTankCapacity; }
    bool isAvailableForTestDrive() { return availableForTestDrive; }
};
