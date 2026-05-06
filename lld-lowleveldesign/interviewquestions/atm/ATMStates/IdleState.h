#pragma once
#include <iostream>
#include "ATMState.h"
#include "../ATMRoomComponents/ATM.h"
#include "../ATMRoomComponents/Card.h"
using namespace std;

class HasCardState;

class IdleState : public ATMState {
public:
    void insertCard(ATM* atm, Card* card) override;
};
