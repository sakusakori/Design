#pragma once
#include <iostream>
#include "Payment.h"
using namespace std;

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash paid: " << amount << endl;
        return true;
    }
};
