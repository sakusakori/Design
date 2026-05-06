#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

// Step 4: Refined Abstractions (Concrete LivingThings)
class Fish : public LivingThings {
public:
    Fish(BreathingProcess* breathingProcess) : LivingThings(breathingProcess) {}

    void breathe() override {
        cout << "Fish: ";
        breathingProcess->breathe(); // Operation implemented by Implementor - defines the "HOW"
    }
};
