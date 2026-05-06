#pragma once
#include <iostream>
#include "ATMState.h"
#include "IdleState.h"
#include "../ATMRoomComponents/ATM.h"
#include "../ATMRoomComponents/Card.h"
using namespace std;

class SelectOperationState;

class HasCardState : public ATMState {
public:
    HasCardState() {
        cout << "enter your card pin number" << endl;
    }

    void authenticatePin(ATM* atm, Card* card, int pin) override;

    void exit(ATM* atm) override {
        returnCard();
        atm->setCurrentATMState(new IdleState());
        cout << "Exit happens" << endl;
    }

    void returnCard() override {
        cout << "Please collect your card" << endl;
    }
};
