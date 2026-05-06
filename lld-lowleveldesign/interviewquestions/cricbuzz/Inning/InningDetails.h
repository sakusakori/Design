#pragma once
#include <vector>
#include "OverDetails.h"
#include "../MatchType.h"
#include "../Team/Team.h"
using namespace std;

class InningDetails {
public:
    Team* battingTeam;
    Team* bowlingTeam;
    MatchType* matchType;
    vector<OverDetails*> overs;

    InningDetails(Team* battingTeam, Team* bowlingTeam, MatchType* matchType)
        : battingTeam(battingTeam), bowlingTeam(bowlingTeam), matchType(matchType) {}

    void start(int runsToWin) {

        //set batting players
        try {
            battingTeam->chooseNextBatsMan();
        } catch (...) {
        }

        int noOfOvers = matchType->noOfOvers();
        for (int overNumber = 1; overNumber <= noOfOvers; overNumber++) {

            //chooseBowler
            bowlingTeam->chooseNextBowler(matchType->maxOverCountBowlers());

            OverDetails* over = new OverDetails(overNumber, bowlingTeam->getCurrentBowler());
            overs.push_back(over);
            try {
                bool won = over->startOver(battingTeam, bowlingTeam, runsToWin);
                if (won == true) {
                    break;
                }
            } catch (...) {
                break;
            }

            //swap striker and non striker
            PlayerDetails* temp = battingTeam->getStriker();
            battingTeam->setStriker(battingTeam->getNonStriker());
            battingTeam->setNonStriker(temp);
        }
    }

    int getTotalRuns() {
        return battingTeam->getTotalRuns();
    }
};
