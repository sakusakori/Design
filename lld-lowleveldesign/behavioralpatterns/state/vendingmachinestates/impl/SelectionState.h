#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include "../State.h"
#include "../Coin.h"
#include "../../context/VendingMachine.h"
#include "IdleState.h"
#include "DispenseState.h"
using namespace std;

class SelectionState : public State {
public:
    SelectionState() {
        cout << "Currently Vending machine is in SelectionState" << endl;
    }

    void chooseProduct(VendingMachine* machine, int codeNumber) override {

        //1. get item of this codeNumber
        Item* item = machine->getInventory()->getItem(codeNumber);

        //2. total amount paid by User
        int paidByUser = 0;
        for (Coin& coin : machine->getCoinList()) {
            paidByUser = paidByUser + coin.value;
        }

        //3. compare product price and amount paid by user
        if (paidByUser < item->getPrice()) {
            cout << "Insufficient Amount, Product you selected is for price: "
                 << item->getPrice() << " and you paid: " << paidByUser << endl;
            refundFullMoney(machine);
            throw runtime_error("insufficient amount");
        }
        else if (paidByUser >= item->getPrice()) {

            if (paidByUser > item->getPrice()) {
                getChange(paidByUser - item->getPrice());
            }
            machine->setVendingMachineState(new DispenseState(machine, codeNumber));
        }
    }

    int getChange(int returnExtraMoney) override {
        //actual logic should be to return COINs in the dispense tray, but for simplicity i am just returning the amount to be refunded
        cout << "Returned the change in the Coin Dispense Tray: " << returnExtraMoney << endl;
        return returnExtraMoney;
    }

    vector<Coin> refundFullMoney(VendingMachine* machine) override {
        cout << "Returned the full amount back in the Coin Dispense Tray" << endl;
        machine->setVendingMachineState(new IdleState(machine));
        return machine->getCoinList();
    }
};
