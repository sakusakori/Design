#pragma once

#include <iostream>
#include "strategy/PaymentStrategy.h"

using namespace std;

// Context class - holds reference to a strategy object
class ShoppingCart {
private:
    PaymentStrategy* paymentStrategy;

public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        this->paymentStrategy = strategy;
    }

    void checkout(double amount) {
        cout << paymentStrategy->getName() << ": ";
        paymentStrategy->pay(amount);
    }
};
