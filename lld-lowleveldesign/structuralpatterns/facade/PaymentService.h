#pragma once
#include <iostream>
#include <string>
using namespace std;

// Subsystem B: Payment
class PaymentService {
public:
    bool makePayment(string paymentMethod) {
        cout << "Processing payment using: " << paymentMethod << endl;
        return true; // assume payment always succeeds
    }
};
