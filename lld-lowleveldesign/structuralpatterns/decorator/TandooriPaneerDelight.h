#pragma once
#include "BasePizza.h"

// Step 2: Define the Concrete Component
class TandooriPaneerDelight : public BasePizza {
public:
    string getDescription() override {
        return "Tandoori Paneer Delight Pizza";
    }

    double getCost() override {
        return 400.0;
    }
};
