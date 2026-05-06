#pragma once

#include <iostream>
#include <string>
#include "Marker.h"

using namespace std;

// GOOD: Following SRP - Each class has a single responsibility

// Responsibility: Managing Invoice data only
class Invoice {
private:
    Marker marker;
    int quantity;
    int total;

public:
    Invoice(Marker marker, int quantity)
        : marker(marker), quantity(quantity), total(0) {}

    // Responsibility 1: Calculate the total(business logic)
    void calculateTotal() {
        cout << "Calculating total..." << endl;
        this->total = this->marker.price * this->quantity;
    }
};
