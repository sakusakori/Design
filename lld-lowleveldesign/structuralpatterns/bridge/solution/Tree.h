#pragma once
#include <iostream>
#include "LivingThings.h"
using namespace std;

// Step 4: Refined Abstractions (Concrete LivingThings)
class Tree : public LivingThings {
public:
    Tree(BreathingProcess* breathingProcess) : LivingThings(breathingProcess) {}

    void breathe() override {
        cout << "Tree: ";
        breathingProcess->breathe(); // Operation implemented by Implementor - defines the "HOW"
    }
};
