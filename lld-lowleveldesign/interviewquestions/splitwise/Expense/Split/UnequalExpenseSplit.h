#pragma once
#include "ExpenseSplit.h"

class UnequalExpenseSplit : public ExpenseSplit {
public:
    void validateSplitRequest(vector<Split*>& splitList, double totalAmount) override {

    }
};
