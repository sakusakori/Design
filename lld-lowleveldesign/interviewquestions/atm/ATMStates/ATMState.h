#pragma once
#include <iostream>
#include "../enums/TransactionType.h"
using namespace std;

class ATM;
class Card;

class ATMState {
public:
    virtual ~ATMState() = default;

    virtual void insertCard(ATM* atm, Card* card) {
        cout << "OOPS!! Something went wrong" << endl;
    }

    virtual void authenticatePin(ATM* atm, Card* card, int pin) {
        cout << "OOPS!! Something went wrong" << endl;
    }

    virtual void selectOperation(ATM* atm, Card* card, TransactionType txnType) {
        cout << "OOPS!! Something went wrong" << endl;
    }

    virtual void cashWithdrawal(ATM* atm, Card* card, int withdrawAmount) {
        cout << "OOPS!! Something went wrong" << endl;
    }

    virtual void displayBalance(ATM* atm, Card* card) {
        cout << "OOPS!! Something went wrong" << endl;
    }

    virtual void returnCard() {
        cout << "OOPS!! Something went wrong" << endl;
    }

    virtual void exit(ATM* atm) {
        cout << "OOPS!! Something went wrong" << endl;
    }
};
