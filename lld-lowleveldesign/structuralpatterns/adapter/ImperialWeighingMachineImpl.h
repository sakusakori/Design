#pragma once
#include "ImperialWeighingMachine.h"

// Adaptee - Existing Incompatible class
class ImperialWeighingMachineImpl : public ImperialWeighingMachine {
private:
    double weightInPounds;

public:
    ImperialWeighingMachineImpl(double weighingScaleReading)
        : weightInPounds(weighingScaleReading) {}

    // Third-party weighing machine (US model) - returns pounds
    double getWeightInPounds() override {
        return weightInPounds;
    }
};
