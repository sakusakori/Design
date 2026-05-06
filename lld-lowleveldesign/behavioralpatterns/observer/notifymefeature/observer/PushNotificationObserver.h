#pragma once
#include <iostream>
#include <string>
#include "StockNotificationObserver.h"
using namespace std;

// Concrete observer for push notifications
class PushNotificationObserver : public StockNotificationObserver {
private:
    string userId;
    string deviceToken;

    void sendPushNotification() {
        cout << "!! PUSH NOTIFICATION SENT to: " << deviceToken << " - "
                  << "Product is back in stock! Hurry Up!!" << endl;
    }

public:
    PushNotificationObserver(string userId, string deviceToken)
        : userId(move(userId)), deviceToken(move(deviceToken)) {}

    void update() override {
        sendPushNotification();
    }

    string getNotificationMethod() override {
        return "Push Notification";
    }

    string getUserId() override {
        return userId;
    }
};
