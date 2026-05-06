#include <iostream>
#include "Marker.h"
#include "Invoice.h"

using namespace std;

// Usage example
int main() {
    Invoice invoice(Marker("name", "color", 10, 2020), 10);
    invoice.calculateTotal();
    invoice.saveToDB();
    invoice.printInvoice();

    return 0;
}
