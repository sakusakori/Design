#pragma once
#include "Payment.h"
#include "../Bill/Bill.h"

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;

    virtual Payment* processPayment(Bill* bill, double paymentAmount) = 0;
};
