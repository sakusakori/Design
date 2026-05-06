#pragma once
#include "MatchType.h"

class T20Match : public MatchType {
public:
    int noOfOvers() override { return 20; }
    int maxOverCountBowlers() override { return 5; }
};
