#pragma once
#include <string>
#include <ctime>
#include "PaymentMode.h"
using namespace std;

class Payment {
private:
    int paymentId;
    int billId;
    double amountPaid;
    PaymentMode paymentMode;
    time_t paymentDate;

public:
    Payment(int paymentId, int billId, double amountPaid,
            PaymentMode paymentMode, time_t paymentDate)
        : paymentId(paymentId), billId(billId), amountPaid(amountPaid),
          paymentMode(paymentMode), paymentDate(paymentDate) {}

    int getPaymentId() { return paymentId; }
    int getBillId() { return billId; }
    double getAmountPaid() { return amountPaid; }
    PaymentMode getPaymentMode() { return paymentMode; }
    time_t getPaymentDate() { return paymentDate; }
};
