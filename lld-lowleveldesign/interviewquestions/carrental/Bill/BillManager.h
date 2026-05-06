#pragma once
#include <map>
#include "Bill.h"
#include "BillingStrategy.h"
#include "../reservation/Reservation.h"
using namespace std;

class BillManager {
private:
    BillingStrategy* billingStrategy;
    // store all bills here
    map<int, Bill*> bills;

public:
    BillManager(BillingStrategy* billingStrategy)
        : billingStrategy(billingStrategy) {}

    Bill* generateBill(Reservation* reservation) {
        Bill* bill = billingStrategy->generateBill(reservation);
        bills[bill->getBillId()] = bill;
        return bill;
    }

    Bill* getBill(int billId) {
        auto it = bills.find(billId);
        if (it != bills.end()) return it->second;
        return nullptr;
    }

    void setBillingStrategy(BillingStrategy* strategy) {
        billingStrategy = strategy;
    }
};
