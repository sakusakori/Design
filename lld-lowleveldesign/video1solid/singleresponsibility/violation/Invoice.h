#pragma once

#include <iostream>
#include <string>
#include "Marker.h"

using namespace std;

// BAD: This class violates SRP by having multiple responsibilities
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

    // Responsibility 2: Print the Invoice
    void printInvoice() {
        // print the Invoice
        cout << "Printing Invoice..." << endl;
    }

    // Responsibility 3: Database Operations
    void saveToDB() {
        // Save the data into DB
        cout << "Saving to DB..." << endl;
    }
};
