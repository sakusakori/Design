#pragma once

#include <iostream>
#include "Invoice.h"

using namespace std;

// Responsibility 2: Managing Database Operations only
class InvoiceDao {
public:
    Invoice invoice;

    InvoiceDao(Invoice invoice) : invoice(invoice) {}

    void saveToDB() {
        // Save into the DB the invoice
        cout << "Saving to DB..." << endl;
    }
};
