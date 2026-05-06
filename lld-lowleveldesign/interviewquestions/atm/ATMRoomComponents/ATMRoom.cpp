#include <iostream>
#include "ATM.h"
#include "Card.h"
#include "User.h"
#include "UserBankAccount.h"
#include "../ATMStates/StateIncludes.h"
#include "../enums/TransactionType.h"
using namespace std;

int main() {

    // create ATM
    ATM* atm = ATM::getATMObject();
    atm->setAtmBalance(3500, 1, 2, 5);

    // create User
    UserBankAccount bankAccount;
    bankAccount.setBalance(3000);

    Card card;
    card.setBankAccount(&bankAccount);

    User user;
    user.setCard(&card);

    atm->printCurrentATMStatus();
    atm->getCurrentATMState()->insertCard(atm, user.getCard());
    atm->getCurrentATMState()->authenticatePin(atm, user.getCard(), 112211);
    atm->getCurrentATMState()->selectOperation(atm, user.getCard(), CASH_WITHDRAWAL);
    atm->getCurrentATMState()->cashWithdrawal(atm, user.getCard(), 2700);
    atm->printCurrentATMStatus();

    return 0;
}
