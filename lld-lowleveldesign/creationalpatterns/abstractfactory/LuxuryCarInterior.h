#pragma once
#include "CarInterior.h"

// Step 3: Concrete Products for Luxury Car Family
class LuxuryCarInterior : public CarInterior {
public:
    void addInteriorComponents() override {
        cout << "Adding luxurious interior components for Luxury Car." << endl;
    }
};
