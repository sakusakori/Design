#pragma once
#include "ExpenseSplitType.h"
#include "Split/ExpenseSplit.h"
#include "Split/EqualExpenseSplit.h"
#include "Split/UnequalExpenseSplit.h"
#include "Split/PercentageExpenseSplit.h"

class SplitFactory {
public:
    static ExpenseSplit* getSplitObject(ExpenseSplitType splitType) {
        switch (splitType) {
            case EQUAL:      return new EqualExpenseSplit();
            case UNEQUAL:    return new UnequalExpenseSplit();
            case PERCENTAGE: return new PercentageExpenseSplit();
            default:         return nullptr;
        }
    }
};
