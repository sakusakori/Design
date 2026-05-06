#pragma once
#include <string>
#include "VehicleType.h"
#include "VehicleStatus.h"
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string vehicleNumber;
    VehicleType vehicleType;
    double dailyRentalCost;
    VehicleStatus vehicleStatus;

public:
    Vehicle(int vehicleID, string vehicleNumber, VehicleType vehicleType)
        : vehicleID(vehicleID), vehicleNumber(move(vehicleNumber)),
          vehicleType(vehicleType), dailyRentalCost(0),
          vehicleStatus(AVAILABLE) {}

    // Getters
    int getVehicleID() { return vehicleID; }
    VehicleType getVehicleType() { return vehicleType; }
    VehicleStatus getVehicleStatus() { return vehicleStatus; }
    double getDailyRentalCost() { return dailyRentalCost; }
    string getVehicleNumber() { return vehicleNumber; }

    // Setters
    void setDailyRentalCost(double cost) { dailyRentalCost = cost; }
    void setStatus(VehicleStatus status) { vehicleStatus = status; }
};
