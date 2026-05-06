#pragma once
#include <vector>
#include "Inventory.h"
#include "../vendingmachinestates/Coin.h"
#include "../vendingmachinestates/State.h"
using namespace std;

// Forward declaration - IdleState is included in the .cpp or after full definition
class IdleState;

class VendingMachine {
private:
    State* vendingMachineState;
    Inventory* inventory;
    vector<Coin> coinList;

public:
    VendingMachine();

    State* getVendingMachineState() { return vendingMachineState; }
    void setVendingMachineState(State* state) { vendingMachineState = state; }

    Inventory* getInventory() { return inventory; }
    void setInventory(Inventory* inv) { inventory = inv; }

    vector<Coin>& getCoinList() { return coinList; }
    void setCoinList(vector<Coin> list) { coinList = move(list); }
};
