#include <iostream>
#include "ShoppingCart.h"
#include "strategy/CreditCardPayment.h"
#include "strategy/PayPalPayment.h"
#include "strategy/UPIPayment.h"

using namespace std;

// Client code - to simulate payment processing
int main() {
    cout << "###### Strategy Design Pattern ######" << endl;
    cout << "###### Example: Payment Processor ######" << endl;

    // Create a shopping cart and set payment strategy
    ShoppingCart cart;

    // Choosing payment behavior at runtime
    CreditCardPayment creditCard("1234-5678-9012-3456");
    cart.setPaymentStrategy(&creditCard);
    cart.checkout(100.0);

    PayPalPayment paypal("johndoe@example.com");
    cart.setPaymentStrategy(&paypal);
    cart.checkout(200.0);

    UPIPayment upi("9988776655@ybl");
    cart.setPaymentStrategy(&upi);
    cart.checkout(300.0);

    // Adding another payment method(crypto) is as simple as adding a new strategy class
    // No need to modify existing code - good design
    // CryptoPayment crypto("BTC");
    // cart.setPaymentStrategy(&crypto);
    // cart.checkout(400.0);

    return 0;
}
