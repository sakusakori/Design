#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include "../enums/PaymentStatus.h"
using namespace std;

class Payment {
private:
    int paymentId;
    PaymentStatus status;

public:
    Payment(PaymentStatus status)
        : paymentId(rand()), status(status) {}

    int getPaymentId() { return paymentId; }
    PaymentStatus getStatus() { return status; }
};
