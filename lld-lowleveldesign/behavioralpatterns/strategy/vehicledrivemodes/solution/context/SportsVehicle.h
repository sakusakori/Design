#pragma once
#include "Vehicle.h"

// Concrete context subclass
class SportsVehicle : public Vehicle {
public:
    SportsVehicle(DriveStrategy* driveStrategy) : Vehicle(driveStrategy) {}
};
