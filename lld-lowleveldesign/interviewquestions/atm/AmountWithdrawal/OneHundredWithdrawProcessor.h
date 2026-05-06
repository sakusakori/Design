#pragma once
#include <iostream>
#include "CashWithdrawProcessor.h"
using namespace std;

class OneHundredWithdrawProcessor : public CashWithdrawProcessor {
public:
    OneHundredWithdrawProcessor(CashWithdrawProcessor* next)
        : CashWithdrawProcessor(next) {}

    void withdraw(ATM* atm, int remainingAmount) override {
        int required = remainingAmount / 100;
        int balance = remainingAmount % 100;

        if (required <= atm->getNoOfOneHundredNotes()) {
            atm->deductOneHundredNotes(required);
        } else if (required > atm->getNoOfOneHundredNotes()) {
            atm->deductOneHundredNotes(atm->getNoOfOneHundredNotes());
            balance = balance + (required - atm->getNoOfOneHundredNotes()) * 100;
        }

        if (balance != 0) {
            cout << "Something went wrong" << endl;
        }
    }
};
