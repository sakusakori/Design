#include <iostream>
#include "Marker.h"
#include "Invoice.h"
#include "InvoiceDao.h"
#include "InvoicePrinter.h"

using namespace std;

// Usage example showing how all classes work together
int main() {
    // create the service objects
    Invoice invoice(Marker("name", "color", 10, 2020), 10);
    InvoiceDao invoiceDao(invoice);
    InvoicePrinter invoicePrinter(invoice);

    // use the services
    invoice.calculateTotal();
    invoiceDao.saveToDB();
    invoicePrinter.print();

    return 0;
}
