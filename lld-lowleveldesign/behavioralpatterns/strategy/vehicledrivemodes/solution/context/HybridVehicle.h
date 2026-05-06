#pragma once
#include "Vehicle.h"

// Concrete context subclass
class HybridVehicle : public Vehicle {
public:
    HybridVehicle(DriveStrategy* driveStrategy) : Vehicle(driveStrategy) {}
};
