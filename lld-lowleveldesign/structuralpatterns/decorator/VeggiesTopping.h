#pragma once
#include "ToppingDecorator.h"

// Step 4: Define the Concrete Decorators
class VeggiesTopping : public ToppingDecorator {
public:
    VeggiesTopping(BasePizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + " + Veggies";
    }

    double getCost() override {
        return pizza->getCost() + 30;
    }
};
