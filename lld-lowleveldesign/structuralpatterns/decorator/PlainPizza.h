#pragma once
#include "BasePizza.h"

// Step 2: Define the Concrete Component
class PlainPizza : public BasePizza {
public:
    string getDescription() override {
        return "Plain Pizza";
    }

    double getCost() override {
        return 200.00;
    }
};
