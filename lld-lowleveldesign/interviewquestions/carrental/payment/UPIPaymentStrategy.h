#pragma once
#include <ctime>
#include "PaymentStrategy.h"
#include "Payment.h"
#include "PaymentMode.h"
#include "../Bill/Bill.h"

class UPIPaymentStrategy : public PaymentStrategy {
private:
    int paymentIdCounter = 9000;

public:
    Payment* processPayment(Bill* bill, double paymentAmount) override {

        Payment* payment = new Payment(
            paymentIdCounter++,
            bill->getBillId(),
            paymentAmount,
            UPI,
            time(nullptr)
        );

        //currently assumption is that payment amount is always equals to bill amount
        //no partial scenario
        bill->setBillPaid(true);

        return payment;
    }
};
