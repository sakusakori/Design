#pragma once
#include "Vehicle.h"

// Concrete context subclass
class OffRoadVehicle : public Vehicle {
public:
    OffRoadVehicle(DriveStrategy* driveStrategy) : Vehicle(driveStrategy) {}
};
