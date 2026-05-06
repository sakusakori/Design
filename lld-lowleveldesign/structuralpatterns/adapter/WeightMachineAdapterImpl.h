#pragma once
#include "WeighingMachineAdapter.h"
#include "ImperialWeighingMachine.h"

// Concrete Adapter converts pounds -> kg
class WeightMachineAdapterImpl : public WeighingMachineAdapter {
private:
    // Adaptee Reference
    ImperialWeighingMachine* imperialWeighingMachine;

public:
    WeightMachineAdapterImpl(ImperialWeighingMachine* weightMachineInPounds)
        : imperialWeighingMachine(weightMachineInPounds) {}

    double getWeightInKg() override {
        double weightInPound = imperialWeighingMachine->getWeightInPounds();
        // Conversion formula: 1 pound = 0.453592 kg
        return weightInPound * 0.45;
    }
};
