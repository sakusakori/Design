#pragma once
#include "Vehicle.h"

class OffRoadVehicle_Problem : public Vehicle_Problem {
public:
    void drive() override {
        cout << "\nOffRoadVehicle: ";
        cout << "Driving Capability: Sports" << endl; // code duplication
    }
};
