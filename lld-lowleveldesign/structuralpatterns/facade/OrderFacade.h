#pragma once
#include <iostream>
#include <string>
#include "InventoryService.h"
#include "PaymentService.h"
#include "ShippingService.h"
#include "NotificationService.h"
using namespace std;

// Facade hides complexity and provides a simple unified interface
class OrderFacade {
private:
    InventoryService inventory;
    PaymentService payment;
    ShippingService shipping;
    NotificationService notification;

public:
    // Simplified method for clients
    void placeOrder(string productId, string paymentMethod) {

        // The following steps are hidden from the client and need to be executed in a specific order
        cout << "Placing order for product: " << productId << endl;

        // Step 1: Check stock
        if (!inventory.checkStock(productId)) {
            cout << "Product out of stock!" << endl;
            return;
        }

        // Step 2: Make payment
        if (!payment.makePayment(paymentMethod)) {
            cout << "Payment failed!" << endl;
            return;
        }

        // Step 3: Ship product
        shipping.shipProduct(productId);

        // Step 4: Send confirmation
        notification.sendConfirmation(productId);

        cout << "Order placed successfully!" << endl;
    }
};
