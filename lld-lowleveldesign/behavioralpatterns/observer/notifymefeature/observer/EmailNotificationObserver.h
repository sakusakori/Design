#pragma once
#include <iostream>
#include <string>
#include "StockNotificationObserver.h"
using namespace std;

// Concrete observer for email notifications
class EmailNotificationObserver : public StockNotificationObserver {
private:
    string userId;
    string emailAddress;

    void sendEmail() {
        cout << "!! EMAIL SENT to: " << emailAddress << " - "
                  << "Product is back in stock! Hurry Up!!" << endl;
    }

public:
    EmailNotificationObserver(string userId, string emailAddress)
        : userId(move(userId)), emailAddress(move(emailAddress)) {}

    void update() override {
        sendEmail();
    }

    string getNotificationMethod() override {
        return "Email";
    }

    string getUserId() override {
        return userId;
    }
};
