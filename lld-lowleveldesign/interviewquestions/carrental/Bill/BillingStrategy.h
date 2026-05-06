#pragma once
#include "Bill.h"

class Reservation;

class BillingStrategy {
public:
    virtual ~BillingStrategy() = default;

    virtual Bill* generateBill(Reservation* reservation) = 0;
};
