#pragma once
#include "UserBankAccount.h"

class Card {
public:
    static const int PIN_NUMBER = 112211;

private:
    int cardNumber;
    int cvv;
    int expiryDate;
    int holderName;
    UserBankAccount* bankAccount;

public:
    Card() : cardNumber(0), cvv(0), expiryDate(0), holderName(0), bankAccount(nullptr) {}

    bool isCorrectPINEntered(int pin) {
        return pin == PIN_NUMBER;
    }

    int getBankBalance() {
        return bankAccount->balance;
    }

    void deductBankBalance(int amount) {
        bankAccount->withdrawalBalance(amount);
    }

    void setBankAccount(UserBankAccount* bankAccount) {
        this->bankAccount = bankAccount;
    }
};
