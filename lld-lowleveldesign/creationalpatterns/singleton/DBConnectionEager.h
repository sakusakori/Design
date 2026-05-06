#pragma once
#include <iostream>
using namespace std;

// 1. Eager Initialization - Singleton
class DBConnectionEager {
private:
    // The private constructor prevents instantiation
    DBConnectionEager() {}

public:
    // Delete copy constructor and assignment operator
    DBConnectionEager(const DBConnectionEager&) = delete;
    DBConnectionEager& operator=(const DBConnectionEager&) = delete;

    // The single instance, created immediately (eager)
    static DBConnectionEager& getInstance() {
        static DBConnectionEager instance;
        return instance;
    }

    // Method to display a message
    void displayMessage() {
        cout << "Eager Initialization - Singleton - " << this << endl;
    }
};
