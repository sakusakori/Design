#pragma once
#include "ExpenseSplit.h"

class PercentageExpenseSplit : public ExpenseSplit {
public:
    void validateSplitRequest(vector<Split*>& splitList, double totalAmount) override {

    }
};
