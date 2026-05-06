#pragma once

// Resolves circular dependencies between states
#include "IdleState.h"
#include "HasCardState.h"
#include "SelectOperationState.h"
#include "CashWithdrawalState.h"
#include "CheckBalanceState.h"

// Deferred method definitions

inline void IdleState::insertCard(ATM* atm, Card* card) {
    cout << "Card is inserted" << endl;
    atm->setCurrentATMState(new HasCardState());
}

inline void HasCardState::authenticatePin(ATM* atm, Card* card, int pin) {
    bool isCorrectPinEntered = card->isCorrectPINEntered(pin);

    if (isCorrectPinEntered) {
        atm->setCurrentATMState(new SelectOperationState());
    } else {
        cout << "Invalid PIN Number" << endl;
        exit(atm);
    }
}

// ATM Singleton
inline ATM* ATM::getATMObject() {
    static ATM atmObject;
    atmObject.setCurrentATMState(new IdleState());
    return &atmObject;
}
