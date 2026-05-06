#pragma once
#include <string>
#include "CarFactory.h"
#include "LuxuryCarInterior.h"
#include "LuxuryCarExterior.h"
using namespace std;

// Step 5: Concrete Factories
class LuxuryCarFactory : public CarFactory {
private:
    string brand;

public:
    LuxuryCarFactory(string brand) : brand(move(brand)) {}

    CarInterior* createInterior() override {
        return new LuxuryCarInterior();
    }

    CarExterior* createExterior() override {
        return new LuxuryCarExterior();
    }
};
