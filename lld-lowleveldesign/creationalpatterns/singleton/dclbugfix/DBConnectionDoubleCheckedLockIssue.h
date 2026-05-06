#pragma once
#include <iostream>
#include <mutex>
using namespace std;

// Singleton - Double Checked Locking - Issue Demo
// Issue: Without atomic/volatile, compiler reordering can cause
// another thread to see a non-null but partially constructed object.
class DBConnectionDoubleCheckedLockIssue {
private:
    static DBConnectionDoubleCheckedLockIssue* connectionObj; // NOT atomic - THE ISSUE
    static mutex mtx;

public:
    int portNumber;

    DBConnectionDoubleCheckedLockIssue(const DBConnectionDoubleCheckedLockIssue&) = delete;
    DBConnectionDoubleCheckedLockIssue& operator=(const DBConnectionDoubleCheckedLockIssue&) = delete;

private:
    // Private constructor
    DBConnectionDoubleCheckedLockIssue(int portNumberValue) : portNumber(portNumberValue) {}

public:
    // Thread Safe Method - but has instruction reordering issue without atomic
    static DBConnectionDoubleCheckedLockIssue* getConnectionObj() {
        if (connectionObj == nullptr) { // First check
            lock_guard<mutex> lock(mtx);
            if (connectionObj == nullptr) { // Second check
                connectionObj = new DBConnectionDoubleCheckedLockIssue(5567);
            }
        }
        return connectionObj;
    }

    // Method to display a message
    void displayMessage() {
        cout << "Singleton - Double Checked Locking - Issue - " << this << endl;
    }
};

// Static member initialization
DBConnectionDoubleCheckedLockIssue* DBConnectionDoubleCheckedLockIssue::connectionObj = nullptr;
mutex DBConnectionDoubleCheckedLockIssue::mtx;
