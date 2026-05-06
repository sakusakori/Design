#pragma once
#include "PricingStrategy.h"

class FixedPricingStrategy : public PricingStrategy {
public:
    double calculate(Ticket* ticket) override {
        return 100;
    }
};
