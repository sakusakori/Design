#pragma once

class Wicket;

class BattingScoreCard {
public:
    int totalRuns;
    int totalBallsPlayed;
    int totalFours;
    int totalSix;
    double strikeRate;
    Wicket* wicketDetails;

    BattingScoreCard()
        : totalRuns(0), totalBallsPlayed(0), totalFours(0),
          totalSix(0), strikeRate(0), wicketDetails(nullptr) {}
};
