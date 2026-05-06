#pragma once
#include "CarInterior.h"

// Step 2: Concrete Products for Economy Car Family
class EconomyCarInterior : public CarInterior {
public:
    void addInteriorComponents() override {
        cout << "Adding basic interior components for Economy Car." << endl;
    }
};
