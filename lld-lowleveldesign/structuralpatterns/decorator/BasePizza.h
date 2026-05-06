#pragma once
#include <string>
using namespace std;

// Step 1: Define the Component Interface
class BasePizza {
public:
    virtual ~BasePizza() = default;

    virtual string getDescription() = 0;

    virtual double getCost() = 0;
};
