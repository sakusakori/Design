#pragma once
#include <iostream>
#include "ATMState.h"
#include "IdleState.h"
#include "../ATMRoomComponents/ATM.h"
#include "../ATMRoomComponents/Card.h"
using namespace std;

class CheckBalanceState : public ATMState {
public:
    CheckBalanceState() {}

    void displayBalance(ATM* atm, Card* card) override {
        cout << "Your Balance is: " << card->getBankBalance() << endl;
        exit(atm);
    }

    void exit(ATM* atm) override {
        returnCard();
        atm->setCurrentATMState(new IdleState());
        cout << "Exit happens" << endl;
    }

    void returnCard() override {
        cout << "Please collect your card" << endl;
    }
};
