#pragma once
#include "CarExterior.h"

// Step 3: Concrete Products for Luxury Car Family
class LuxuryCarExterior : public CarExterior {
public:
    void addExteriorComponents() override {
        cout << "Adding luxurious exterior components for Luxury Car." << endl;
    }
};
