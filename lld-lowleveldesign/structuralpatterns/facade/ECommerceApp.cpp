#include <iostream>
#include "OrderFacade.h"
using namespace std;

// Client Usage
int main() {
    cout << "====== Facade Design Pattern Demo ======" << endl;

    // Client interacts with a simple Facade, not with all subsystems.
    OrderFacade orderFacade;

    // Place order with one call to Facade
    orderFacade.placeOrder("MacBook Pro", "Credit Card");

    // Place another order with one call to Facade
    orderFacade.placeOrder("Cricket Bat", "UPI");

    return 0;
}
