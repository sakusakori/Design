#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// A simple payment processor class - bloated with payment logic
class PaymentProcessor {
public:
    void processPayment(string type, double amount) {
        if (type == "credit_card") {
            // x lines of credit card logic
            cout << "Paid $" << amount << " using credit card" << endl;
        }
        else if (type == "paypal") {
            // y lines of PayPal logic
            cout << "Paid $" << amount << " using PayPal" << endl;
        }
        else if (type == "net_banking") {
            // z lines of bank transfer logic
            cout << "Paid $" << amount << " using bank transfer" << endl;
        }
        else if (type == "cash") {
            // 10 lines of cash on delivery logic
            cout << "Paid $" << amount << " using cash" << endl;
        }
        else {
            throw invalid_argument("Unexpected value: " + type);
        }
        // Adding another payment method(crypto) requires modifying this class
        // This keeps growing with each new payment method
        // bad design
    }
};
