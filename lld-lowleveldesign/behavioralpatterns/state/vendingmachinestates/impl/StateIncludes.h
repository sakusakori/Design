#pragma once

// This file resolves circular dependencies between states.
// Include this file wherever you need all state implementations.

#include "IdleState.h"
#include "HasMoneyState.h"
#include "SelectionState.h"
#include "DispenseState.h"

// Deferred method definitions (due to circular includes)

inline void IdleState::clickOnInsertCoinButton(VendingMachine* machine) {
    machine->setVendingMachineState(new HasMoneyState());
}

inline void HasMoneyState::clickOnStartProductSelectionButton(VendingMachine* machine) {
    machine->setVendingMachineState(new SelectionState());
}

// VendingMachine constructor (needs IdleState)
inline VendingMachine::VendingMachine() {
    vendingMachineState = new IdleState();
    inventory = new Inventory(10);
}
