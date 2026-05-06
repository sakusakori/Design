#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

// Step 4: Refined Abstractions (Concrete LivingThings)
class Dog : public LivingThings {
public:
    Dog(BreathingProcess* breathingProcess) : LivingThings(breathingProcess) {}

    void breathe() override {
        cout << "Dog: ";
        breathingProcess->breathe(); // Operation implemented by Implementor - defines the "HOW"
    }
};
