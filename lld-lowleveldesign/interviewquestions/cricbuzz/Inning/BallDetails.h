#pragma once
#include <vector>
#include <cstdlib>
#include "BallType.h"
#include "RunType.h"
#include "../Team/Player/PlayerDetails.h"
#include "../Team/Wicket.h"
#include "../Team/Team.h"
#include "../ScoreUpdater/ScoreUpdaterObserver.h"
#include "../ScoreUpdater/BattingScoreUpdater.h"
#include "../ScoreUpdater/BowlingScoreUpdater.h"
using namespace std;

class OverDetails;

class BallDetails {
public:
    int ballNumber;
    BallType ballType;
    RunType runType;
    PlayerDetails* playedBy;
    PlayerDetails* bowledBy;
    Wicket* wicket;
    vector<ScoreUpdaterObserver*> scoreUpdaterObserverList;

    BallDetails(int ballNumber) : ballNumber(ballNumber), ballType(NORMAL),
        runType(ZERO), playedBy(nullptr), bowledBy(nullptr), wicket(nullptr) {
        scoreUpdaterObserverList.push_back(new BowlingScoreUpdater());
        scoreUpdaterObserverList.push_back(new BattingScoreUpdater());
    }

    void startBallDelivery(Team* battingTeam, Team* bowlingTeam, OverDetails* over);

private:
    void notifyUpdaters(BallDetails* ballDetails) {
        for (ScoreUpdaterObserver* observer : scoreUpdaterObserverList) {
            observer->update(ballDetails);
        }
    }

    RunType getRunType() {
        double val = (double)rand() / RAND_MAX;
        if (val <= 0.2) {
            return ONE;
        } else if (val >= 0.3 && val <= 0.5) {
            return TWO;
        } else if (val >= 0.6 && val <= 0.8) {
            return FOUR;
        } else {
            return SIX;
        }
    }

    bool isWicketTaken() {
        if ((double)rand() / RAND_MAX < 0.2) {
            return true;
        } else {
            return false;
        }
    }
};
