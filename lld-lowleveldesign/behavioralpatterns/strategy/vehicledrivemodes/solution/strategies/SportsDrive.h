#pragma once
#include <iostream>
#include "DriveStrategy.h"
using namespace std;

// Concrete strategy for sports drive mode
class SportsDrive : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving Capability: Sports" << endl;
    }
};
