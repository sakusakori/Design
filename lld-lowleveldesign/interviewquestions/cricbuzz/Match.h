#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "MatchType.h"
#include "Team/Team.h"
#include "Inning/InningDetails.h"
using namespace std;

class Match {
public:
    Team* teamA;
    Team* teamB;
    string venue;
    Team* tossWinner;
    InningDetails* innings[2];
    MatchType* matchType;

    Match(Team* teamA, Team* teamB, string venue, MatchType* matchType)
        : teamA(teamA), teamB(teamB), venue(move(venue)),
          tossWinner(nullptr), matchType(matchType) {
        innings[0] = nullptr;
        innings[1] = nullptr;
    }

    void startMatch() {

        //1. Toss
        tossWinner = toss(teamA, teamB);

        //start The Inning, there are 2 innings in a match
        for (int inning = 1; inning <= 2; inning++) {

            InningDetails* inningDetails;
            Team* bowlingTeam;
            Team* battingTeam;

            //assuming here that tossWinner batFirst
            if (inning == 1) {
                battingTeam = tossWinner;
                bowlingTeam = (tossWinner->getTeamName() == teamA->getTeamName()) ? teamB : teamA;
                inningDetails = new InningDetails(battingTeam, bowlingTeam, matchType);
                inningDetails->start(-1);
            } else {
                bowlingTeam = tossWinner;
                battingTeam = (tossWinner->getTeamName() == teamA->getTeamName()) ? teamB : teamA;
                inningDetails = new InningDetails(battingTeam, bowlingTeam, matchType);
                inningDetails->start(innings[0]->getTotalRuns());
                if (bowlingTeam->getTotalRuns() > battingTeam->getTotalRuns()) {
                    bowlingTeam->isWinner = true;
                }
            }

            innings[inning - 1] = inningDetails;

            //print inning details
            cout << endl;
            cout << "INNING " << inning << " -- total Run: " << battingTeam->getTotalRuns() << endl;
            cout << "---Batting ScoreCard : " << battingTeam->teamName << "---" << endl;
            battingTeam->printBattingScoreCard();

            cout << endl;
            cout << "---Bowling ScoreCard : " << bowlingTeam->teamName << "---" << endl;
            bowlingTeam->printBowlingScoreCard();
        }

        cout << endl;
        if (teamA->isWinner) {
            cout << "---WINNER---" << teamA->teamName << endl;
        } else {
            cout << "---WINNER---" << teamB->teamName << endl;
        }
    }

private:
    Team* toss(Team* teamA, Team* teamB) {
        if ((double)rand() / RAND_MAX < 0.5) {
            return teamA;
        } else {
            return teamB;
        }
    }
};
