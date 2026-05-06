#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle_Problem {
public:
    virtual ~Vehicle_Problem() = default;

    virtual void drive() {
        cout << "\nVehicle: ";
        cout << "Driving Capability: Normal" << endl;
    }
};
