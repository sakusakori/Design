#pragma once
#include <iostream>
#include "DriveStrategy.h"
using namespace std;

// Concrete strategy for electric drive mode
class EVDrive : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving Capability: Electric" << endl;
    }
};
