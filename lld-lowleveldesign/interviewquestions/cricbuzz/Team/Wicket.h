#pragma once
#include "WicketType.h"
#include "Player/PlayerDetails.h"

class OverDetails;
class BallDetails;

class Wicket {
public:
    WicketType wicketType;
    PlayerDetails* takenBy;
    OverDetails* overDetail;
    BallDetails* ballDetail;

    Wicket(WicketType wicketType, PlayerDetails* takenBy, OverDetails* overDetail, BallDetails* ballDetail)
        : wicketType(wicketType), takenBy(takenBy), overDetail(overDetail), ballDetail(ballDetail) {}
};
