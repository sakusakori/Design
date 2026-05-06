#pragma once
#include <string>
#include <vector>
#include "Expense.h"
#include "ExpenseSplitType.h"
#include "SplitFactory.h"
#include "Split/Split.h"
#include "Split/ExpenseSplit.h"
#include "../BalanceSheetController.h"
#include "../User/User.h"
using namespace std;

class ExpenseController {
public:
    BalanceSheetController balanceSheetController;

    Expense* createExpense(string expenseId, string description, double expenseAmount,
                           vector<Split*>& splitDetails, ExpenseSplitType splitType, User* paidByUser) {

        ExpenseSplit* expenseSplit = SplitFactory::getSplitObject(splitType);
        expenseSplit->validateSplitRequest(splitDetails, expenseAmount);

        Expense* expense = new Expense(expenseId, expenseAmount, description, paidByUser, splitType, splitDetails);

        balanceSheetController.updateUserExpenseBalanceSheet(paidByUser, splitDetails, expenseAmount);

        delete expenseSplit;
        return expense;
    }
};
