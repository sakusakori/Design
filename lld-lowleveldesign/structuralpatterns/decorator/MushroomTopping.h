#pragma once
#include "ToppingDecorator.h"

// Step 4: Define the Concrete Decorators
class MushroomTopping : public ToppingDecorator {
public:
    MushroomTopping(BasePizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + " + Mushroom";
    }

    double getCost() override {
        return pizza->getCost() + 40;
    }
};
