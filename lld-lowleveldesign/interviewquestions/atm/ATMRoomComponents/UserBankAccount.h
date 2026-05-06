#pragma once

class UserBankAccount {
public:
    int balance;

    UserBankAccount() : balance(0) {}

    void withdrawalBalance(int amount) {
        balance = balance - amount;
    }

    int getBalance() { return balance; }
    void setBalance(int balance) { this->balance = balance; }
};
