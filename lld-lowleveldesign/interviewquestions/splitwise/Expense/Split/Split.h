#pragma once
#include "../../User/User.h"

class Split {
public:
    User* user;
    double amountOwe;

    Split(User* user, double amountOwe)
        : user(user), amountOwe(amountOwe) {}

    User* getUser() { return user; }
    void setUser(User* user) { this->user = user; }

    double getAmountOwe() { return amountOwe; }
    void setAmountOwe(double amount) { amountOwe = amount; }
};
