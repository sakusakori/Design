#pragma once
#include <iostream>
#include "CarInterior.h"
#include "CarExterior.h"
using namespace std;

// Step 4: Abstract Factory interface
class CarFactory {
public:
    virtual ~CarFactory() = default;

    // Factory methods
    virtual CarInterior* createInterior() = 0;

    virtual CarExterior* createExterior() = 0;

    // Template method that uses all factory methods
    void produceCompleteVehicle() {
        cout << "Starting complete vehicle production..." << endl;

        // Create all components
        CarInterior* interior = createInterior();
        CarExterior* exterior = createExterior();

        // Assemble the vehicle
        interior->addInteriorComponents();
        exterior->addExteriorComponents();

        cout << "Vehicle production completed!" << endl;

        delete interior;
        delete exterior;
    }
};
