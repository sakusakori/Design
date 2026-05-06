#pragma once
#include "../ATMRoomComponents/ATM.h"

class CashWithdrawProcessor {
public:
    CashWithdrawProcessor* nextCashWithdrawalProcessor;

    CashWithdrawProcessor(CashWithdrawProcessor* next)
        : nextCashWithdrawalProcessor(next) {}

    virtual ~CashWithdrawProcessor() = default;

    virtual void withdraw(ATM* atm, int remainingAmount) {
        if (nextCashWithdrawalProcessor != nullptr) {
            nextCashWithdrawalProcessor->withdraw(atm, remainingAmount);
        }
    }
};
