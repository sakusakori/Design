#pragma once

#include <iostream>

using namespace std;

// Strategy interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual string getName() = 0;
    virtual ~PaymentStrategy() = default;
};
