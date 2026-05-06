#pragma once

#include <iostream>
#include <string>
#include "PaymentStrategy.h"

using namespace std;

// Concrete strategy - for UPI payment
class UPIPayment : public PaymentStrategy {
private:
    string upiId;

public:
    UPIPayment(string upiId) {
        this->upiId = upiId;
    }

    void pay(double amount) override {
        cout << "Paid $" << amount << " using UPI ID " << upiId << endl;
    }

    string getName() override {
        return "UPIPayment";
    }
};
