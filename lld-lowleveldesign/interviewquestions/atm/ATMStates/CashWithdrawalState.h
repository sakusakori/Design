#pragma once
#include <iostream>
#include "ATMState.h"
#include "IdleState.h"
#include "../ATMRoomComponents/ATM.h"
#include "../ATMRoomComponents/Card.h"
#include "../AmountWithdrawal/TwoThousandWithdrawProcessor.h"
#include "../AmountWithdrawal/FiveHundredWithdrawProcessor.h"
#include "../AmountWithdrawal/OneHundredWithdrawProcessor.h"
using namespace std;

class CashWithdrawalState : public ATMState {
public:
    CashWithdrawalState() {
        cout << "Please enter the Withdrawal Amount" << endl;
    }

    void cashWithdrawal(ATM* atmObject, Card* card, int withdrawalAmountRequest) override {
        if (atmObject->getAtmBalance() < withdrawalAmountRequest) {
            cout << "Insufficient fund in the ATM Machine" << endl;
            exit(atmObject);
        } else if (card->getBankBalance() < withdrawalAmountRequest) {
            cout << "Insufficient fund in the your Bank Account" << endl;
            exit(atmObject);
        } else {
            card->deductBankBalance(withdrawalAmountRequest);
            atmObject->deductATMBalance(withdrawalAmountRequest);

            //using chain of responsibility for this logic, how many 2k Rs notes, how many 500 Rs notes etc, has to be withdrawal
            OneHundredWithdrawProcessor oneH(nullptr);
            FiveHundredWithdrawProcessor fiveH(&oneH);
            TwoThousandWithdrawProcessor twoK(&fiveH);

            twoK.withdraw(atmObject, withdrawalAmountRequest);
            exit(atmObject);
        }
    }

    void exit(ATM* atmObject) override {
        returnCard();
        atmObject->setCurrentATMState(new IdleState());
        cout << "Exit happens" << endl;
    }

    void returnCard() override {
        cout << "Please collect your card" << endl;
    }
};
