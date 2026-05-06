#pragma once
#include <string>
#include <vector>
#include "ExpenseSplitType.h"
#include "Split/Split.h"
#include "../User/User.h"
using namespace std;

class Expense {
public:
    string expenseId;
    string description;
    double expenseAmount;
    User* paidByUser;
    ExpenseSplitType splitType;
    vector<Split*> splitDetails;

    Expense(string expenseId, double expenseAmount, string description,
            User* paidByUser, ExpenseSplitType splitType, vector<Split*>& splitDetails)
        : expenseId(move(expenseId)), expenseAmount(expenseAmount),
          description(move(description)), paidByUser(paidByUser),
          splitType(splitType), splitDetails(splitDetails) {}
};
