#pragma once
#include <vector>
#include <string>
#include "User/User.h"
#include "User/UserController.h"
#include "Group/Group.h"
#include "Group/GroupController.h"
#include "BalanceSheetController.h"
#include "Expense/ExpenseSplitType.h"
#include "Expense/Split/Split.h"
using namespace std;

class Splitwise {
public:
    UserController userController;
    GroupController groupController;
    BalanceSheetController balanceSheetController;

    void demo() {

        setupUserAndGroup();

        //Step1: add members to the group
        Group* group = groupController.getGroup("G1001");
        group->addMember(userController.getUser("U2001"));
        group->addMember(userController.getUser("U3001"));

        //Step2. create an expense inside a group
        vector<Split*> splits;
        Split split1(userController.getUser("U1001"), 300);
        Split split2(userController.getUser("U2001"), 300);
        Split split3(userController.getUser("U3001"), 300);
        splits.push_back(&split1);
        splits.push_back(&split2);
        splits.push_back(&split3);
        group->createExpense("Exp1001", "Breakfast", 900, splits, EQUAL, userController.getUser("U1001"));

        vector<Split*> splits2;
        Split splits2_1(userController.getUser("U1001"), 400);
        Split splits2_2(userController.getUser("U2001"), 100);
        splits2.push_back(&splits2_1);
        splits2.push_back(&splits2_2);
        group->createExpense("Exp1002", "Lunch", 500, splits2, UNEQUAL, userController.getUser("U2001"));

        for (User* user : userController.getAllUsers()) {
            balanceSheetController.showBalanceSheetOfUser(user);
        }
    }

    void setupUserAndGroup() {

        //onboard user to splitwise app
        addUsersToSplitwiseApp();

        //create a group by user1
        User* user1 = userController.getUser("U1001");
        groupController.createNewGroup("G1001", "Outing with Friends", user1);
    }

private:
    void addUsersToSplitwiseApp() {

        //adding User1
        userController.addUser(new User("U1001", "User1"));

        //adding User2
        userController.addUser(new User("U2001", "User2"));

        //adding User3
        userController.addUser(new User("U3001", "User3"));
    }
};
