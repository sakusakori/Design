#pragma once
#include "Vehicle.h"

// Concrete context subclass
class GoodsVehicle : public Vehicle {
public:
    GoodsVehicle(DriveStrategy* driveStrategy) : Vehicle(driveStrategy) {}
};
