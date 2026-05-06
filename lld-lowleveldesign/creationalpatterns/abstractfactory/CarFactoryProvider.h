#pragma once
#include <string>
#include <stdexcept>
#include "CarFactory.h"
#include "EconomyCarFactory.h"
#include "LuxuryCarFactory.h"
using namespace std;

enum CarType {
    ECONOMY, LUXURY, PREMIUM
};

// Step 6: Factory Provider
class CarFactoryProvider {
public:
    CarFactory* getFactory(CarType type, string brand) {
        switch (type) {
            case ECONOMY:
                return new EconomyCarFactory(brand);
            case PREMIUM:
            case LUXURY:
                return new LuxuryCarFactory(brand);
            default:
                throw invalid_argument("Unknown car type");
        }
    }
};
