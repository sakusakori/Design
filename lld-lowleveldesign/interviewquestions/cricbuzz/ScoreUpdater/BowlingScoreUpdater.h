#pragma once
#include "ScoreUpdaterObserver.h"
#include "../Inning/RunType.h"
#include "../Inning/BallType.h"

class BallDetails;

class BowlingScoreUpdater : public ScoreUpdaterObserver {
public:
    void update(BallDetails* ballDetails) override;
};
