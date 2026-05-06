#pragma once
#include <iostream>
#include <mutex>
using namespace std;

// 3. Thread Safe Singleton
class DBConnectionThreadSafe {
private:
    static DBConnectionThreadSafe* instance;
    static mutex mtx;

    // Private Constructor
    DBConnectionThreadSafe() {}

public:
    DBConnectionThreadSafe(const DBConnectionThreadSafe&) = delete;
    DBConnectionThreadSafe& operator=(const DBConnectionThreadSafe&) = delete;

    // Thread Safe Method to return the unique instance of this class
    static DBConnectionThreadSafe* getInstance() {
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr) {
            instance = new DBConnectionThreadSafe();
        }
        return instance;
    }

    // Method to display a message
    void displayMessage() {
        cout << "Thread Safe Singleton - " << this << endl;
    }
};

// Static member initialization
DBConnectionThreadSafe* DBConnectionThreadSafe::instance = nullptr;
mutex DBConnectionThreadSafe::mtx;
