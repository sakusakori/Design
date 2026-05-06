#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "PlayerType.h"
#include "Score/BattingScoreCard.h"
#include "Score/BowlingScoreCard.h"
using namespace std;

class Wicket;

class PlayerDetails {
public:
    Person* person;
    PlayerType playerType;
    BattingScoreCard* battingScoreCard;
    BowlingScoreCard* bowlingScoreCard;

    PlayerDetails(Person* person, PlayerType playerType)
        : person(person), playerType(playerType) {
        battingScoreCard = new BattingScoreCard();
        bowlingScoreCard = new BowlingScoreCard();
    }

    void printBattingScoreCard() {
        string outBy = "notout";
        if (battingScoreCard->wicketDetails != nullptr) {
            // will be resolved when Wicket is fully defined
            outBy = "out";
        }
        cout << "PlayerName: " << person->name
             << " -- totalRuns: " << battingScoreCard->totalRuns
             << " -- totalBallsPlayed: " << battingScoreCard->totalBallsPlayed
             << " -- 4s: " << battingScoreCard->totalFours
             << " -- 6s: " << battingScoreCard->totalSix
             << " -- outby: " << outBy << endl;
    }

    void printBowlingScoreCard() {
        cout << "PlayerName: " << person->name
             << " -- totalOversThrown: " << bowlingScoreCard->totalOversCount
             << " -- totalRunsGiven: " << bowlingScoreCard->runsGiven
             << " -- WicketsTaken: " << bowlingScoreCard->wicketsTaken << endl;
    }
};
