#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

class Tree_Problem : public LivingThings_Problem {
public:
    // Breathing Process is tightly coupled to the LivingThings(abstraction)
    void breathe() override {
        cout << "Tree: Breathes through leaves; Lives on land; Respiratory system: Leaves" << endl;
        cout << "Breathing Process: Inhales Carbon Dioxide and Exhales Oxygen as a result of photosynthesis." << endl;
    }
};
