#pragma once
#include <vector>
#include "User.h"
using namespace std;

class UserController {
public:
    vector<User*> userList;

    // add user
    void addUser(User* user) {
        userList.push_back(user);
    }

    User* getUser(string userID) {
        for (User* user : userList) {
            if (user->getUserId() == userID) {
                return user;
            }
        }
        return nullptr;
    }

    vector<User*>& getAllUsers() {
        return userList;
    }
};
