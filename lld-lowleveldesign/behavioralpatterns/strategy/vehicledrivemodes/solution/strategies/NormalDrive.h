#pragma once
#include <iostream>
#include "DriveStrategy.h"
using namespace std;

// Concrete strategy for normal drive mode
class NormalDrive : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving Capability: Normal" << endl;
    }
};
