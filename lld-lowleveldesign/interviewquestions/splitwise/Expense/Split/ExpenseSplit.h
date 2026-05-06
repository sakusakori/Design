#pragma once
#include <vector>
#include "Split.h"
using namespace std;

class ExpenseSplit {
public:
    virtual ~ExpenseSplit() = default;

    virtual void validateSplitRequest(vector<Split*>& splitList, double totalAmount) = 0;
};
