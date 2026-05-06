#include <iostream>
#include "context/VendingMachine.h"
#include "context/Item.h"
#include "context/ItemShelf.h"
#include "context/ItemType.h"
#include "vendingmachinestates/Coin.h"
#include "vendingmachinestates/State.h"
#include "vendingmachinestates/impl/StateIncludes.h"
using namespace std;

void fillUpInventory(VendingMachine* vendingMachine) {
    vector<ItemShelf*>& slots = vendingMachine->getInventory()->getInventory();
    for (int i = 0; i < (int)slots.size(); i++) {
        Item* newItem = new Item();
        if (i >= 0 && i < 3) {
            newItem->setType(COKE);
            newItem->setPrice(12);
        } else if (i >= 3 && i < 5) {
            newItem->setType(PEPSI);
            newItem->setPrice(9);
        } else if (i >= 5 && i < 7) {
            newItem->setType(JUICE);
            newItem->setPrice(13);
        } else if (i >= 7 && i < 10) {
            newItem->setType(SODA);
            newItem->setPrice(7);
        }
        slots[i]->setItem(newItem);
        slots[i]->setSoldOut(false);
    }
}

void displayInventory(VendingMachine* vendingMachine) {
    vector<ItemShelf*>& slots = vendingMachine->getInventory()->getInventory();
    for (int i = 0; i < (int)slots.size(); i++) {
        cout << "CodeNumber: " << slots[i]->getCode()
             << " Item: " << itemTypeName(slots[i]->getItem()->getType())
             << " Price: " << slots[i]->getItem()->getPrice()
             << " isAvailable: " << (!slots[i]->isSoldOut() ? "true" : "false") << endl;
    }
}

int main() {

    VendingMachine vendingMachine;
    try {

        cout << "|" << endl;
        cout << "filling up the inventory" << endl;
        cout << "|" << endl;

        fillUpInventory(&vendingMachine);
        displayInventory(&vendingMachine);

        cout << "|" << endl;
        cout << "clicking on InsertCoinButton" << endl;
        cout << "|" << endl;

        State* vendingState = vendingMachine.getVendingMachineState();
        vendingState->clickOnInsertCoinButton(&vendingMachine);

        vendingState = vendingMachine.getVendingMachineState();
        vendingState->insertCoin(&vendingMachine, NICKEL);
        vendingState->insertCoin(&vendingMachine, QUARTER);
        // vendingState->insertCoin(&vendingMachine, NICKEL);

        cout << "|" << endl;
        cout << "clicking on ProductSelectionButton" << endl;
        cout << "|" << endl;
        vendingState->clickOnStartProductSelectionButton(&vendingMachine);

        vendingState = vendingMachine.getVendingMachineState();
        vendingState->chooseProduct(&vendingMachine, 102);

        displayInventory(&vendingMachine);

    } catch (exception& e) {
        displayInventory(&vendingMachine);
    }

    return 0;
}
