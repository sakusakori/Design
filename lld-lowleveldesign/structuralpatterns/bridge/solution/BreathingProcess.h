#pragma once

// Step 1: Implementor (Breathing process)
class BreathingProcess {
public:
    virtual ~BreathingProcess() = default;
    virtual void breathe() = 0;
};
