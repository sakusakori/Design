#pragma once

#include <iostream>
#include "Invoice.h"

using namespace std;

// Responsibility 3: Printing the Invoice only
class InvoicePrinter {
private:
    Invoice invoice;

public:
    InvoicePrinter(Invoice invoice) : invoice(invoice) {}

    void print() {
        // print the invoice
        cout << "Printing Invoice..." << endl;
    }
};
