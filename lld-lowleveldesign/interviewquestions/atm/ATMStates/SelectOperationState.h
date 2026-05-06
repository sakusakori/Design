#pragma once
#include <iostream>
#include "ATMState.h"
#include "IdleState.h"
#include "CashWithdrawalState.h"
#include "CheckBalanceState.h"
#include "../ATMRoomComponents/ATM.h"
#include "../ATMRoomComponents/Card.h"
#include "../enums/TransactionType.h"
using namespace std;

class SelectOperationState : public ATMState {
public:
    SelectOperationState() {
        showOperations();
    }

    void selectOperation(ATM* atmObject, Card* card, TransactionType txnType) override {
        switch (txnType) {
            case CASH_WITHDRAWAL:
                atmObject->setCurrentATMState(new CashWithdrawalState());
                break;
            case BALANCE_CHECK:
                atmObject->setCurrentATMState(new CheckBalanceState());
                break;
            default:
                cout << "Invalid Option" << endl;
                exit(atmObject);
                break;
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

private:
    void showOperations() {
        cout << "Please select the Operation" << endl;
        showAllTransactionTypes();
    }
};
