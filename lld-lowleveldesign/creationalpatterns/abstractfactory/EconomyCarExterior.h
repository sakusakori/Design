#pragma once
#include "CarExterior.h"

// Step 2: Concrete Products for Economy Car Family
class EconomyCarExterior : public CarExterior {
public:
    void addExteriorComponents() override {
        cout << "Adding basic exterior components for Economy Car." << endl;
    }
};
