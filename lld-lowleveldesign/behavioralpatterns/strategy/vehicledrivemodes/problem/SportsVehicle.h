#pragma once
#include "Vehicle.h"

class SportsVehicle_Problem : public Vehicle_Problem {
public:
    void drive() override {
        cout << "\nSportsVehicle: ";
        cout << "Driving Capability: Sports" << endl;
    }
};
