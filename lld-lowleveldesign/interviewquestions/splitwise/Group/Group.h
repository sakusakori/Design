#pragma once
#include <string>
#include <vector>
#include "../User/User.h"
#include "../Expense/Expense.h"
#include "../Expense/ExpenseController.h"
#include "../Expense/ExpenseSplitType.h"
#include "../Expense/Split/Split.h"
using namespace std;

class Group {
public:
    string groupId;
    string groupName;
    vector<User*> groupMembers;
    vector<Expense*> expenseList;
    ExpenseController expenseController;

    //add member to group
    void addMember(User* member) {
        groupMembers.push_back(member);
    }

    string getGroupId() { return groupId; }
    void setGroupId(string id) { groupId = move(id); }
    void setGroupName(string name) { groupName = move(name); }

    Expense* createExpense(string expenseId, string description, double expenseAmount,
                           vector<Split*>& splitDetails, ExpenseSplitType splitType, User* paidByUser) {

        Expense* expense = expenseController.createExpense(expenseId, description, expenseAmount, splitDetails, splitType, paidByUser);
        expenseList.push_back(expense);
        return expense;
    }
};
