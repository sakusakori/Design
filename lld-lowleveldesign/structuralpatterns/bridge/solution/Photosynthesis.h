#pragma once
#include <iostream>
#include "BreathingProcess.h"
using namespace std;

// Step 2: Concrete Implementor (various breathing processes)
class Photosynthesis : public BreathingProcess {
public:
    void breathe() override {
        cout << "Breathing through process of photosynthesis. Releases Oxygen through leaves." << endl;
    }
};
