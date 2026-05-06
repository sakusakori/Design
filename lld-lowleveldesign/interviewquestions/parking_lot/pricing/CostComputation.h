#pragma once
#include "PricingStrategy.h"

class CostComputation {
private:
    PricingStrategy* pricingStrategy;

public:
    CostComputation(PricingStrategy* pricingStrategy)
        : pricingStrategy(pricingStrategy) {}

    double compute(Ticket* ticket) {
        return pricingStrategy->calculate(ticket);
    }
};
