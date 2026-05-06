#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

class Dog_Problem : public LivingThings_Problem {
public:
    // Breathing Process is tightly coupled to the LivingThings(abstraction)
    void breathe() override {
        cout << "Dog: Breathes through its nose; Lives on land; Respiratory system: 2 lungs" << endl;
        cout << "Breathing Process: Inhales Oxygen from the air and Exhales Carbon Dioxide." << endl;
    }
};
