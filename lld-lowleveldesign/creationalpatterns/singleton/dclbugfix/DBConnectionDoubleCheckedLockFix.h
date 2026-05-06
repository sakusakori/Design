#pragma once
#include <iostream>
#include <mutex>
#include <atomic>
using namespace std;

// Singleton - Double Checked Locking - Fix Demo
// Fix: Using atomic ensures proper memory ordering,
// preventing other threads from seeing a partially constructed object.
class DBConnectionDoubleCheckedLockFix {
private:
    // atomic is used to ensure proper memory ordering (like Java's volatile)
    static atomic<DBConnectionDoubleCheckedLockFix*> connectionObj;
    static mutex mtx;

public:
    int portNumber;

    DBConnectionDoubleCheckedLockFix(const DBConnectionDoubleCheckedLockFix&) = delete;
    DBConnectionDoubleCheckedLockFix& operator=(const DBConnectionDoubleCheckedLockFix&) = delete;

private:
    DBConnectionDoubleCheckedLockFix(int portNumberValue) : portNumber(portNumberValue) {}

public:
    // Thread Safe Method with proper atomic fix
    static DBConnectionDoubleCheckedLockFix* getConnectionObj(int portNumberValue) {
        DBConnectionDoubleCheckedLockFix* tmp = connectionObj.load();
        if (tmp == nullptr) {
            lock_guard<mutex> lock(mtx);
            tmp = connectionObj.load();
            if (tmp == nullptr) {
                tmp = new DBConnectionDoubleCheckedLockFix(portNumberValue);
                connectionObj.store(tmp);
            }
        }
        return tmp;
    }

    // Method to display a message
    void displayMessage() {
        cout << "Singleton - Double Checked Locking - Fix - " << this << endl;
    }
};

// Static member initialization
atomic<DBConnectionDoubleCheckedLockFix*> DBConnectionDoubleCheckedLockFix::connectionObj{nullptr};
mutex DBConnectionDoubleCheckedLockFix::mtx;
