#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "StockAvailabilityObservable.h"
#include "../observer/StockNotificationObserver.h"
using namespace std;

// Concrete Observable
class IphoneProductObservable : public StockAvailabilityObservable {
private:
    string productId;
    string productName;
    double price;
    vector<StockNotificationObserver*> stockObservers;
    int stockQuantity;

public:
    IphoneProductObservable(string productId, string productName, double price, int stockQuantity)
        : productId(move(productId)), productName(move(productName)),
          price(price), stockQuantity(stockQuantity) {}

    void addStockObserver(StockNotificationObserver* observer) override {
        stockObservers.push_back(observer);
        cout << "[+]" << observer->getUserId() << " subscribed for notifications on "
                  << productName << endl;
    }

    void removeStockObserver(StockNotificationObserver* observer) override {
        auto it = find(stockObservers.begin(), stockObservers.end(), observer);
        if (it != stockObservers.end()) {
            stockObservers.erase(it);
        }
        cout << "[-]" << observer->getUserId() << " unsubscribed for notifications on "
                  << productName << endl;
    }

    void notifyStockObservers() override {
        if (stockQuantity > 0 && !stockObservers.empty()) {
            cout << "Notifying " << stockObservers.size() << " subscribers... " << endl;

            // Create a copy to avoid concurrent modification
            vector<StockNotificationObserver*> observersToNotify(stockObservers);

            for (StockNotificationObserver* observer : observersToNotify) {
                observer->update();
            }
        }
    }

    // Method to restock items
    void restock(int quantity) override {
        bool wasOutOfStock = (stockQuantity == 0);
        stockQuantity += quantity;
        cout << "RESTOCKED: " << productName << " - Added " << quantity << " items "
                  << " | " << "Current stock: " << stockQuantity << endl;
        // Only notify if product was previously out of stock
        if (wasOutOfStock && stockQuantity > 0) {
            notifyStockObservers();
        }
    }

    // Method to purchase items
    bool purchase(int quantity) override {
        if (stockQuantity >= quantity) {
            stockQuantity -= quantity;
            cout << "PURCHASE SUCCESS: " << quantity << " units of " << productName
                      << " | " << "Remaining stock: " << stockQuantity << endl;
            return true;
        } else {
            cout << "PURCHASE FAILED: " << productName << " is out of stock! | "
                      << "Available Quantity: " << stockQuantity << endl;
            return false;
        }
    }

    // Getters
    string getProductId() { return productId; }
    string getProductName() { return productName; }
    double getPrice() { return price; }
    int getStockQuantity() { return stockQuantity; }
};
