#pragma once
#include "BreathingProcess.h"

// Step 3: Abstraction for LivingThings
class LivingThings {
protected:
    // Reference to Implementor
    BreathingProcess* breathingProcess;

public:
    virtual ~LivingThings() = default;

    // Bridge connects Animal with Breathing
    LivingThings(BreathingProcess* breathingProcess)
        : breathingProcess(breathingProcess) {}

    // Operation implemented by Implementor
    virtual void breathe() = 0;
};
