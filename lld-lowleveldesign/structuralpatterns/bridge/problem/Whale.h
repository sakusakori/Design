#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

class Whale_Problem : public LivingThings_Problem {
public:
    // Breathing Process is tightly coupled to the LivingThings(abstraction)
    void breathe() override {
        cout << "Whale: Breathes through lungs; Lives in water; Respiratory system: 2 lungs" << endl;
        cout << "Breathing Process: Inhales Oxygen from the water and Exhales Carbon Dioxide" << endl;
    }
};
