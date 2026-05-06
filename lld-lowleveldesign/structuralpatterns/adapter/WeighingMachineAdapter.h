#pragma once

// Target or Adapter Interface
class WeighingMachineAdapter {
public:
    virtual ~WeighingMachineAdapter() = default;

    virtual double getWeightInKg() = 0; // Client wants weight in KG
};
