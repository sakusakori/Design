#pragma once
#include <iostream>
#include <vector>
#include "../State.h"
#include "../Coin.h"
#include "../../context/VendingMachine.h"
using namespace std;

class HasMoneyState;

class IdleState : public State {
public:
    IdleState() {
        cout << "Currently Vending machine is in IdleState" << endl;
    }

    IdleState(VendingMachine* machine) {
        cout << "Currently Vending machine is in IdleState" << endl;
        machine->setCoinList(vector<Coin>());
    }

    void clickOnInsertCoinButton(VendingMachine* machine) override;

    void updateInventory(VendingMachine* machine, Item* item, int codeNumber) override {
        machine->getInventory()->addItem(item, codeNumber);
    }
};
