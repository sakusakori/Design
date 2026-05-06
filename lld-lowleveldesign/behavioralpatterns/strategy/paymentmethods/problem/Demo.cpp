#include <iostream>
#include "PaymentProcessor.h"

using namespace std;

int main() {
    cout << "Payment Processor: Problem Demo" << endl;
    PaymentProcessor processor;
    processor.processPayment("credit_card", 100);
    processor.processPayment("paypal", 200);
    processor.processPayment("net_banking", 300);
    processor.processPayment("cash", 400);
    return 0;
}
