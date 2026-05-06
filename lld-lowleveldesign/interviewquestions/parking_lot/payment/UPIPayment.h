#pragma once
#include <iostream>
#include "Payment.h"
using namespace std;

class UPIPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "UPI paid: " << amount << endl;
        return true;
    }
};
