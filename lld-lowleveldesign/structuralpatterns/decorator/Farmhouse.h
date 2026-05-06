#pragma once
#include "BasePizza.h"

// Step 2: Define the Concrete Component
class Farmhouse : public BasePizza {
public:
    string getDescription() override {
        return "Farmhouse Pizza";
    }

    double getCost() override {
        return 300.0;
    }
};
