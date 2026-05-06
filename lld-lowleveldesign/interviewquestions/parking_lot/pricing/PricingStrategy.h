#pragma once

class Ticket;

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;

    virtual double calculate(Ticket* ticket) = 0;
};
