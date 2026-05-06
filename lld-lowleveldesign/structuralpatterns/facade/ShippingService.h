#pragma once
#include <iostream>
#include <string>
using namespace std;

// Subsystem C: Shipping
class ShippingService {
public:
    void shipProduct(string productId) {
        cout << "Shipping product: " << productId << endl;
    }
};
