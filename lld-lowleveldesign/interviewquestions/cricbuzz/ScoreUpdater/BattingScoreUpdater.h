#pragma once
#include "ScoreUpdaterObserver.h"
#include "../Inning/RunType.h"

class BallDetails;

class BattingScoreUpdater : public ScoreUpdaterObserver {
public:
    void update(BallDetails* ballDetails) override;
};
