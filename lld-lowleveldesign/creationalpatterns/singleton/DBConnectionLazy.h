#pragma once
#include <iostream>
using namespace std;

// 2. Lazy Initialization Singleton
class DBConnectionLazy {
private:
    static DBConnectionLazy* instance;

    // The private constructor prevents instantiation
    DBConnectionLazy() {}

public:
    DBConnectionLazy(const DBConnectionLazy&) = delete;
    DBConnectionLazy& operator=(const DBConnectionLazy&) = delete;

    // Singleton Object is created only when it is required
    // Drawback: This implementation is not thread-safe.
    static DBConnectionLazy* getInstance() {
        if (instance == nullptr) {
            instance = new DBConnectionLazy();
        }
        return instance;
    }

    // Method to display a message
    void displayMessage() {
        cout << "Lazy Initialization - Singleton - " << this << endl;
    }
};

// Static member initialization
DBConnectionLazy* DBConnectionLazy::instance = nullptr;
