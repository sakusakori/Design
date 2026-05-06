#pragma once
#include <iostream>
#include <string>
using namespace std;

// Subsystem D: Notification
class NotificationService {
public:
    void sendConfirmation(string productId) {
        cout << "Sending order confirmation for product: " << productId << endl;
    }
};
