#pragma once
#include <iostream>
#include <vector>
#include "../State.h"
#include "../Coin.h"
#include "../../context/VendingMachine.h"
using namespace std;

class SelectionState;

class HasMoneyState : public State {
public:
    HasMoneyState() {
        cout << "Currently Vending machine is in HasMoneyState" << endl;
    }

    void clickOnStartProductSelectionButton(VendingMachine* machine) override;

    void insertCoin(VendingMachine* machine, Coin coin) override {
        cout << "Accepted the coin" << endl;
        machine->getCoinList().push_back(coin);
    }

    vector<Coin> refundFullMoney(VendingMachine* machine) override {
        cout << "Returned the full amount back in the Coin Dispense Tray" << endl;
        machine->setVendingMachineState(new IdleState(machine));
        return machine->getCoinList();
    }
};
