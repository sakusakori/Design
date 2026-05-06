#pragma once
#include "ToppingDecorator.h"

// Step 4: Define the Concrete Decorators
class ExtraCheeseTopping : public ToppingDecorator {
public:
    ExtraCheeseTopping(BasePizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + " + Extra Cheese";
    }

    double getCost() override {
        return pizza->getCost() + 20;
    }
};
