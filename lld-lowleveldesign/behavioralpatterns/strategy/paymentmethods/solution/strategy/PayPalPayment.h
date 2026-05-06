#pragma once

#include <iostream>
#include <string>
#include "PaymentStrategy.h"

using namespace std;

// Concrete strategy - for PayPal payment
class PayPalPayment : public PaymentStrategy {
private:
    string email;

public:
    PayPalPayment(string email) {
        this->email = email;
    }

    void pay(double amount) override {
        cout << "Paid $" << amount << " using PayPal account " << email << endl;
    }

    string getName() override {
        return "PayPalPayment";
    }
};
