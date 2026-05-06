#pragma once
#include "CashWithdrawProcessor.h"

class TwoThousandWithdrawProcessor : public CashWithdrawProcessor {
public:
    TwoThousandWithdrawProcessor(CashWithdrawProcessor* next)
        : CashWithdrawProcessor(next) {}

    void withdraw(ATM* atm, int remainingAmount) override {
        int required = remainingAmount / 2000;
        int balance = remainingAmount % 2000;

        if (required <= atm->getNoOfTwoThousandNotes()) {
            atm->deductTwoThousandNotes(required);
        } else if (required > atm->getNoOfTwoThousandNotes()) {
            atm->deductTwoThousandNotes(atm->getNoOfTwoThousandNotes());
            balance = balance + (required - atm->getNoOfTwoThousandNotes()) * 2000;
        }

        if (balance != 0) {
            CashWithdrawProcessor::withdraw(atm, balance);
        }
    }
};
