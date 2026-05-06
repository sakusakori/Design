#pragma once
#include "MatchType.h"

class OneDayMatch : public MatchType {
public:
    int noOfOvers() override { return 50; }
    int maxOverCountBowlers() override { return 10; }
};
