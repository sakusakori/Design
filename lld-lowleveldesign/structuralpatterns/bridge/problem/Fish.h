#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

class Fish_Problem : public LivingThings_Problem {
public:
    // Breathing Process is tightly coupled to the LivingThings(abstraction)
    void breathe() override {
        cout << "Fish: Breathes through gills; Lives in water; Respiratory system: 2 gills" << endl;
        cout << "Breathing Process: Absorbs Oxygen from the water and releases Carbon Dioxide." << endl;
    }
};
