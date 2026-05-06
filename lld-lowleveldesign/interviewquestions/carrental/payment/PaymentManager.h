#pragma once
#include <map>
#include <vector>
#include "Payment.h"
#include "PaymentStrategy.h"
#include "../Bill/Bill.h"
using namespace std;

class PaymentManager {
private:
    PaymentStrategy* paymentStrategy;
    map<int, Payment*> payments;

public:
    PaymentManager(PaymentStrategy* paymentStrategy)
        : paymentStrategy(paymentStrategy) {}

    Payment* makePayment(Bill* bill, double paymentAmount) {
        Payment* payment = paymentStrategy->processPayment(bill, paymentAmount);
        payments[payment->getPaymentId()] = payment;
        return payment;
    }

    vector<Payment*> getPaymentsForBill(int billId) {
        vector<Payment*> result;
        for (auto& pair : payments) {
            if (pair.second->getBillId() == billId) {
                result.push_back(pair.second);
            }
        }
        return result;
    }

    Payment* getPayment(int paymentId) {
        auto it = payments.find(paymentId);
        if (it != payments.end()) return it->second;
        return nullptr;
    }

    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }
};
