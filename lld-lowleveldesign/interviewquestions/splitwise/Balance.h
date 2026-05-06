#pragma once

class Balance {
public:
    double amountOwe;
    double amountGetBack;

    Balance() : amountOwe(0), amountGetBack(0) {}

    double getAmountOwe() { return amountOwe; }
    void setAmountOwe(double amount) { amountOwe = amount; }

    double getAmountGetBack() { return amountGetBack; }
    void setAmountGetBack(double amount) { amountGetBack = amount; }
};
