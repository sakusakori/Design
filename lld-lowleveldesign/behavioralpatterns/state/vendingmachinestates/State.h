#pragma once
#include <vector>
#include "Coin.h"
#include "../context/Item.h"
using namespace std;

class VendingMachine;

class State {
public:
    virtual ~State() = default;

    virtual void clickOnInsertCoinButton(VendingMachine* machine) {
        // by default nothing happens
    }

    virtual void clickOnStartProductSelectionButton(VendingMachine* machine) {
        // by default nothing happens
    }

    virtual void insertCoin(VendingMachine* machine, Coin coin) {
        // by default nothing happens
    }

    virtual void chooseProduct(VendingMachine* machine, int codeNumber) {
        // by default nothing happens
    }

    virtual int getChange(int returnChangeMoney) {
        // by default nothing happens
        return 0;
    }

    virtual Item* dispenseProduct(VendingMachine* machine, int codeNumber) {
        // by default nothing happens
        return nullptr;
    }

    virtual vector<Coin> refundFullMoney(VendingMachine* machine) {
        // by default nothing happens
        return {};
    }

    virtual void updateInventory(VendingMachine* machine, Item* item, int codeNumber) {
        // by default nothing happens
    }
};
