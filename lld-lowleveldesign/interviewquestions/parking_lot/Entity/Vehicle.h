#pragma once
#include <string>
#include "../enums/VehicleType.h"
using namespace std;

class Vehicle {
private:
    string vehicleNumber;
    VehicleType vehicleType;

public:
    Vehicle(string vehicleNumber, VehicleType vehicleType)
        : vehicleNumber(move(vehicleNumber)), vehicleType(vehicleType) {}

    string getVehicleNumber() {
        return vehicleNumber;
    }

    VehicleType getVehicleType() {
        return vehicleType;
    }
};
