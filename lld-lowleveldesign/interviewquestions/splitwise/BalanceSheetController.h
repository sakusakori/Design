#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Balance.h"
#include "UserExpenseBalanceSheet.h"
#include "User/User.h"
#include "Expense/Split/Split.h"
using namespace std;

class BalanceSheetController {
public:
    void updateUserExpenseBalanceSheet(User* expensePaidBy, vector<Split*>& splits, double totalExpenseAmount) {

        //update the total amount paid of the expense paid by user
        UserExpenseBalanceSheet* paidByUserExpenseSheet = expensePaidBy->getUserExpenseBalanceSheet();
        paidByUserExpenseSheet->setTotalPayment(paidByUserExpenseSheet->getTotalPayment() + totalExpenseAmount);

        for (Split* split : splits) {

            User* userOwe = split->getUser();
            UserExpenseBalanceSheet* oweUserExpenseSheet = userOwe->getUserExpenseBalanceSheet();
            double oweAmount = split->getAmountOwe();

            if (expensePaidBy->getUserId() == userOwe->getUserId()) {
                paidByUserExpenseSheet->setTotalYourExpense(paidByUserExpenseSheet->getTotalYourExpense() + oweAmount);
            } else {

                //update the balance of paid user
                paidByUserExpenseSheet->setTotalYouGetBack(paidByUserExpenseSheet->getTotalYouGetBack() + oweAmount);

                Balance* userOweBalance;
                auto& paidMap = paidByUserExpenseSheet->getUserVsBalance();
                if (paidMap.find(userOwe->getUserId()) != paidMap.end()) {
                    userOweBalance = paidMap[userOwe->getUserId()];
                } else {
                    userOweBalance = new Balance();
                    paidMap[userOwe->getUserId()] = userOweBalance;
                }

                userOweBalance->setAmountGetBack(userOweBalance->getAmountGetBack() + oweAmount);

                //update the balance sheet of owe user
                oweUserExpenseSheet->setTotalYouOwe(oweUserExpenseSheet->getTotalYouOwe() + oweAmount);
                oweUserExpenseSheet->setTotalYourExpense(oweUserExpenseSheet->getTotalYourExpense() + oweAmount);

                Balance* userPaidBalance;
                auto& oweMap = oweUserExpenseSheet->getUserVsBalance();
                if (oweMap.find(expensePaidBy->getUserId()) != oweMap.end()) {
                    userPaidBalance = oweMap[expensePaidBy->getUserId()];
                } else {
                    userPaidBalance = new Balance();
                    oweMap[expensePaidBy->getUserId()] = userPaidBalance;
                }
                userPaidBalance->setAmountOwe(userPaidBalance->getAmountOwe() + oweAmount);
            }
        }
    }

    void showBalanceSheetOfUser(User* user) {

        cout << "---------------------------------------" << endl;
        cout << "Balance sheet of user : " << user->getUserId() << endl;

        UserExpenseBalanceSheet* sheet = user->getUserExpenseBalanceSheet();

        cout << "TotalYourExpense: " << sheet->getTotalYourExpense() << endl;
        cout << "TotalGetBack: " << sheet->getTotalYouGetBack() << endl;
        cout << "TotalYourOwe: " << sheet->getTotalYouOwe() << endl;
        cout << "TotalPaymnetMade: " << sheet->getTotalPayment() << endl;

        for (auto& entry : sheet->getUserVsBalance()) {
            string userID = entry.first;
            Balance* balance = entry.second;
            cout << "userID:" << userID << " YouGetBack:" << balance->getAmountGetBack()
                 << " YouOwe:" << balance->getAmountOwe() << endl;
        }

        cout << "---------------------------------------" << endl;
    }
};
