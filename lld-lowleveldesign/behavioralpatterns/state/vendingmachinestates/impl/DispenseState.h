#pragma once
#include <iostream>
#include "../State.h"
#include "../../context/VendingMachine.h"
#include "IdleState.h"
using namespace std;

class DispenseState : public State {
public:
    DispenseState(VendingMachine* machine, int codeNumber) {
        cout << "Currently Vending machine is in DispenseState" << endl;
        dispenseProduct(machine, codeNumber);
    }

    Item* dispenseProduct(VendingMachine* machine, int codeNumber) override {
        cout << "Product has been dispensed" << endl;
        Item* item = machine->getInventory()->getItem(codeNumber);
        machine->getInventory()->updateSoldOutItem(codeNumber);
        machine->setVendingMachineState(new IdleState(machine));
        return item;
    }
};
