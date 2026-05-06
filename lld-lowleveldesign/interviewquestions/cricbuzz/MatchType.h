#pragma once

class MatchType {
public:
    virtual ~MatchType() = default;
    virtual int noOfOvers() = 0;
    virtual int maxOverCountBowlers() = 0;
};
