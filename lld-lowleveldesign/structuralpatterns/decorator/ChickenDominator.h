#pragma once
#include "BasePizza.h"

// Step 2: Define the Concrete Component
class ChickenDominator : public BasePizza {
public:
    string getDescription() override {
        return "Chicken Dominator Pizza";
    }

    double getCost() override {
        return 500.0;
    }
};
