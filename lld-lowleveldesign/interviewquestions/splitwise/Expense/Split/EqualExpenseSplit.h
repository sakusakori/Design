#pragma once
#include "ExpenseSplit.h"

class EqualExpenseSplit : public ExpenseSplit {
public:
    void validateSplitRequest(vector<Split*>& splitList, double totalAmount) override {

        //validate total amount in splits of each user is equal and overall equals to totalAmount or not
        double amountShouldBePresent = totalAmount / splitList.size();
        for (Split* split : splitList) {
            if (split->getAmountOwe() != amountShouldBePresent) {
                //throw exception
            }
        }
    }
};
