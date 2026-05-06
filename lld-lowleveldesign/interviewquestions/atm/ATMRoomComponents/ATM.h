#pragma once
#include <iostream>
#include "../ATMStates/ATMState.h"
using namespace std;

class ATM {
public:
    ATMState* currentATMState;
    int noOfTwoThousandNotes;
    int noOfFiveHundredNotes;
    int noOfOneHundredNotes;

private:
    int atmBalance;

    ATM() : currentATMState(nullptr), noOfTwoThousandNotes(0),
            noOfFiveHundredNotes(0), noOfOneHundredNotes(0), atmBalance(0) {}

public:
    // Singleton: eager initialization
    static ATM* getATMObject();

    ATMState* getCurrentATMState() { return currentATMState; }
    void setCurrentATMState(ATMState* state) { currentATMState = state; }

    int getAtmBalance() { return atmBalance; }

    void setAtmBalance(int balance, int twoK, int fiveH, int oneH) {
        atmBalance = balance;
        noOfTwoThousandNotes = twoK;
        noOfFiveHundredNotes = fiveH;
        noOfOneHundredNotes = oneH;
    }

    int getNoOfTwoThousandNotes() { return noOfTwoThousandNotes; }
    int getNoOfFiveHundredNotes() { return noOfFiveHundredNotes; }
    int getNoOfOneHundredNotes() { return noOfOneHundredNotes; }

    void deductATMBalance(int amount) { atmBalance -= amount; }
    void deductTwoThousandNotes(int number) { noOfTwoThousandNotes -= number; }
    void deductFiveHundredNotes(int number) { noOfFiveHundredNotes -= number; }
    void deductOneHundredNotes(int number) { noOfOneHundredNotes -= number; }

    void printCurrentATMStatus() {
        cout << "Balance: " << atmBalance << endl;
        cout << "2kNotes: " << noOfTwoThousandNotes << endl;
        cout << "500Notes: " << noOfFiveHundredNotes << endl;
        cout << "100Notes: " << noOfOneHundredNotes << endl;
    }
};
