#pragma once
#include <iostream>
#include <string>
using namespace std;

enum TransactionType {
    CASH_WITHDRAWAL,
    BALANCE_CHECK
};

inline void showAllTransactionTypes() {
    cout << "CASH_WITHDRAWAL" << endl;
    cout << "BALANCE_CHECK" << endl;
}
