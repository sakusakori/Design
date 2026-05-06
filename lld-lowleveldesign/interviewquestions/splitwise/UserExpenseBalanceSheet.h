#pragma once
#include <map>
#include <string>
#include "Balance.h"
using namespace std;

class UserExpenseBalanceSheet {
public:
    map<string, Balance*> userVsBalance;
    double totalYourExpense;
    double totalPayment;
    double totalYouOwe;
    double totalYouGetBack;

    UserExpenseBalanceSheet()
        : totalYourExpense(0), totalPayment(0), totalYouOwe(0), totalYouGetBack(0) {}

    map<string, Balance*>& getUserVsBalance() { return userVsBalance; }

    double getTotalYourExpense() { return totalYourExpense; }
    void setTotalYourExpense(double val) { totalYourExpense = val; }

    double getTotalYouOwe() { return totalYouOwe; }
    void setTotalYouOwe(double val) { totalYouOwe = val; }

    double getTotalYouGetBack() { return totalYouGetBack; }
    void setTotalYouGetBack(double val) { totalYouGetBack = val; }

    double getTotalPayment() { return totalPayment; }
    void setTotalPayment(double val) { totalPayment = val; }
};
