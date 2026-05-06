#pragma once

// Adaptee Interface
// Third-party weighing machine (US model) - returns pounds
class ImperialWeighingMachine {
public:
    virtual ~ImperialWeighingMachine() = default;

    //return the weight in Pound
    virtual double getWeightInPounds() = 0;
};
