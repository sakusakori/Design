#pragma once
#include <iostream>
#include <mutex>
#include <atomic>
using namespace std;

// 4. Double Locking Singleton
class DBConnectionDoubleLocking {
private:
    static atomic<DBConnectionDoubleLocking*> instance;
    static mutex mtx;

    // Private constructor
    DBConnectionDoubleLocking() {}

public:
    DBConnectionDoubleLocking(const DBConnectionDoubleLocking&) = delete;
    DBConnectionDoubleLocking& operator=(const DBConnectionDoubleLocking&) = delete;

    // Thread Safe Method using double-checked locking
    static DBConnectionDoubleLocking* getInstance() {
        DBConnectionDoubleLocking* tmp = instance.load();
        if (tmp == nullptr) { // First check
            lock_guard<mutex> lock(mtx);
            tmp = instance.load();
            if (tmp == nullptr) { // Second check
                tmp = new DBConnectionDoubleLocking();
                instance.store(tmp);
            }
        }
        return tmp;
    }

    // Method to display a message
    void displayMessage() {
        cout << "Double Locking Singleton - " << this << endl;
    }
};

// Static member initialization
atomic<DBConnectionDoubleLocking*> DBConnectionDoubleLocking::instance{nullptr};
mutex DBConnectionDoubleLocking::mtx;
