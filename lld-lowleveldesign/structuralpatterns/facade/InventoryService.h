#pragma once
#include <iostream>
#include <string>
using namespace std;

// Subsystem A: Inventory
class InventoryService {
public:
    bool checkStock(string productId) {
        cout << "Checking stock for product: " << productId << endl;
        return true; // assume it's always in stock
    }
};
