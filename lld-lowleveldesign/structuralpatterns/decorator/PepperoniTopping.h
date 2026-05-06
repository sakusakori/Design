#pragma once
#include "ToppingDecorator.h"

// Step 4: Define the Concrete Decorators
class PepperoniTopping : public ToppingDecorator {
public:
    PepperoniTopping(BasePizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + " + Pepperoni";
    }

    double getCost() override {
        return pizza->getCost() + 50;
    }
};
