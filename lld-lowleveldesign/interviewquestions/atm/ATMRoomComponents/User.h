#pragma once
#include "Card.h"

class User {
public:
    Card* card;
    UserBankAccount* bankAccount;

    User() : card(nullptr), bankAccount(nullptr) {}

    Card* getCard() { return card; }
    void setCard(Card* card) { this->card = card; }
};
