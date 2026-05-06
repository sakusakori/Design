#pragma once
#include <string>
#include "CarFactory.h"
#include "EconomyCarInterior.h"
#include "EconomyCarExterior.h"
using namespace std;

// Step 5: Concrete Factories
class EconomyCarFactory : public CarFactory {
private:
    string brand;

public:
    EconomyCarFactory(string brand) : brand(move(brand)) {}

    CarInterior* createInterior() override {
        return new EconomyCarInterior();
    }

    CarExterior* createExterior() override {
        return new EconomyCarExterior();
    }
};
