#pragma once
#include "BasePizza.h"

// Step 3: Define the Abstract Base Decorator
class ToppingDecorator : public BasePizza {
protected:
    BasePizza* pizza;

public:
    ToppingDecorator(BasePizza* pizza) : pizza(pizza) {}
};
