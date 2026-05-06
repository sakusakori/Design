#pragma once

class BallDetails;

class ScoreUpdaterObserver {
public:
    virtual ~ScoreUpdaterObserver() = default;
    virtual void update(BallDetails* ballDetails) = 0;
};
