#pragma once
#include "CashWithdrawProcessor.h"

class FiveHundredWithdrawProcessor : public CashWithdrawProcessor {
public:
    FiveHundredWithdrawProcessor(CashWithdrawProcessor* next)
        : CashWithdrawProcessor(next) {}

    void withdraw(ATM* atm, int remainingAmount) override {
        int required = remainingAmount / 500;
        int balance = remainingAmount % 500;

        if (required <= atm->getNoOfFiveHundredNotes()) {
            atm->deductFiveHundredNotes(required);
        } else if (required > atm->getNoOfFiveHundredNotes()) {
            atm->deductFiveHundredNotes(atm->getNoOfFiveHundredNotes());
            balance = balance + (required - atm->getNoOfFiveHundredNotes()) * 500;
        }

        if (balance != 0) {
            CashWithdrawProcessor::withdraw(atm, balance);
        }
    }
};
