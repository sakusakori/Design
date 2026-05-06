#pragma once
#include <string>
#include "../UserExpenseBalanceSheet.h"
using namespace std;

class User {
public:
    string userId;
    string userName;
    UserExpenseBalanceSheet* userExpenseBalanceSheet;

    User(string id, string userName)
        : userId(move(id)), userName(move(userName)) {
        userExpenseBalanceSheet = new UserExpenseBalanceSheet();
    }

    string getUserId() { return userId; }

    UserExpenseBalanceSheet* getUserExpenseBalanceSheet() { return userExpenseBalanceSheet; }
};
