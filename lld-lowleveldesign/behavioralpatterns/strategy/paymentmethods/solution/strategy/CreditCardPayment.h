#pragma once

#include <iostream>
#include <string>
#include "PaymentStrategy.h"

using namespace std;

// Concrete strategy - for credit card payment
class CreditCardPayment : public PaymentStrategy {
private:
    string cardNumber;

public:
    CreditCardPayment(string cardNumber) {
        this->cardNumber = cardNumber;
    }

    void pay(double amount) override {
        cout << "Paid $" << amount << " using credit card ending in "
             << cardNumber.substr(cardNumber.length() - 4) << endl;
    }

    string getName() override {
        return "CreditCardPayment";
    }
};
