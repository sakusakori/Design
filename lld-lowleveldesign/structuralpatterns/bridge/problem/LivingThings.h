#pragma once

// Approach without bridge: breathing logic hardcoded inside LivingThings
class LivingThings_Problem {
public:
    virtual ~LivingThings_Problem() = default;
    virtual void breathe() = 0;
};
