#pragma once
#include <vector>
#include "BallDetails.h"
#include "BallType.h"
#include "../Team/Player/PlayerDetails.h"
#include "../Team/Team.h"
using namespace std;

class OverDetails {
public:
    int overNumber;
    vector<BallDetails*> balls;
    int extraBallsCount;
    PlayerDetails* bowledBy;

    OverDetails(int overNumber, PlayerDetails* bowledBy)
        : overNumber(overNumber), extraBallsCount(0), bowledBy(bowledBy) {}

    bool startOver(Team* battingTeam, Team* bowlingTeam, int runsToWin) {

        int ballCount = 1;
        while (ballCount <= 6) {

            BallDetails* ball = new BallDetails(ballCount);
            ball->startBallDelivery(battingTeam, bowlingTeam, this);
            if (ball->ballType == NORMAL) {
                balls.push_back(ball);
                ballCount++;
                if (ball->wicket != nullptr) {
                    battingTeam->chooseNextBatsMan();
                }

                if (runsToWin != -1 && battingTeam->getTotalRuns() >= runsToWin) {
                    battingTeam->isWinner = true;
                    return true;
                }
            } else {
                extraBallsCount++;
            }
        }

        return false;
    }
};

// Deferred definition - needs OverDetails to be complete
inline void BallDetails::startBallDelivery(Team* battingTeam, Team* bowlingTeam, OverDetails* over) {

    playedBy = battingTeam->getStriker();
    this->bowledBy = over->bowledBy;
    //THROW BALL AND GET THE BALL TYPE, assuming here that ball type is always NORMAL
    ballType = NORMAL;

    //wicket or no wicket
    if (isWicketTaken()) {
        runType = ZERO;
        //considering only BOLD
        wicket = new Wicket(BOLD, bowlingTeam->getCurrentBowler(), over, this);
        //making only striker out for now
        battingTeam->setStriker(nullptr);
    } else {
        runType = getRunType();

        if (runType == ONE || runType == THREE) {
            //swap striker and non striker
            PlayerDetails* temp = battingTeam->getStriker();
            battingTeam->setStriker(battingTeam->getNonStriker());
            battingTeam->setNonStriker(temp);
        }
    }

    //update player scoreboard
    notifyUpdaters(this);
}

// Deferred ScoreUpdater definitions - need BallDetails to be complete
inline void BattingScoreUpdater::update(BallDetails* ballDetails) {
    int run = 0;

    if (ONE == ballDetails->runType) {
        run = 1;
    } else if (TWO == ballDetails->runType) {
        run = 2;
    } else if (FOUR == ballDetails->runType) {
        run = 4;
        ballDetails->playedBy->battingScoreCard->totalFours++;
    } else if (SIX == ballDetails->runType) {
        run = 6;
        ballDetails->playedBy->battingScoreCard->totalSix++;
    }
    ballDetails->playedBy->battingScoreCard->totalRuns += run;
    ballDetails->playedBy->battingScoreCard->totalBallsPlayed++;

    if (ballDetails->wicket != nullptr) {
        ballDetails->playedBy->battingScoreCard->wicketDetails = ballDetails->wicket;
    }
}

inline void BowlingScoreUpdater::update(BallDetails* ballDetails) {
    if (ballDetails->ballNumber == 6 && ballDetails->ballType == NORMAL) {
        ballDetails->bowledBy->bowlingScoreCard->totalOversCount++;
    }

    if (ONE == ballDetails->runType) {
        ballDetails->bowledBy->bowlingScoreCard->runsGiven += 1;
    } else if (TWO == ballDetails->runType) {
        ballDetails->bowledBy->bowlingScoreCard->runsGiven += 2;
    } else if (FOUR == ballDetails->runType) {
        ballDetails->bowledBy->bowlingScoreCard->runsGiven += 4;
    } else if (SIX == ballDetails->runType) {
        ballDetails->bowledBy->bowlingScoreCard->runsGiven += 6;
    }

    if (ballDetails->wicket != nullptr) {
        ballDetails->bowledBy->bowlingScoreCard->wicketsTaken++;
    }

    if (ballDetails->ballType == NOBALL) {
        ballDetails->bowledBy->bowlingScoreCard->noBallCount++;
    }

    if (ballDetails->ballType == WIDEBALL) {
        ballDetails->bowledBy->bowlingScoreCard->wideBallCount++;
    }
}
