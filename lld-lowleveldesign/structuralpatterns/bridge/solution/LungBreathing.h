#pragma once
#include <iostream>
#include "BreathingProcess.h"
using namespace std;

// Step 2: Concrete Implementor (various breathing processes)
class LungBreathing : public BreathingProcess {
public:
    void breathe() override {
        cout << "Breathing through lungs." << endl;
    }
};
