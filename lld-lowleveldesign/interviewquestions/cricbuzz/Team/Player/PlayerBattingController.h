#pragma once
#include <queue>
#include <stdexcept>
#include "PlayerDetails.h"
using namespace std;

class PlayerBattingController {
public:
    queue<PlayerDetails*> yetToPlay;
    PlayerDetails* striker;
    PlayerDetails* nonStriker;

    PlayerBattingController(queue<PlayerDetails*> playing11)
        : yetToPlay(playing11), striker(nullptr), nonStriker(nullptr) {}

    void getNextPlayer() {
        if (yetToPlay.empty()) {
            throw runtime_error("No more batsmen");
        }

        if (striker == nullptr) {
            striker = yetToPlay.front();
            yetToPlay.pop();
        }

        if (nonStriker == nullptr) {
            nonStriker = yetToPlay.front();
            yetToPlay.pop();
        }
    }

    PlayerDetails* getStriker() { return striker; }
    void setStriker(PlayerDetails* player) { striker = player; }

    PlayerDetails* getNonStriker() { return nonStriker; }
    void setNonStriker(PlayerDetails* player) { nonStriker = player; }
};
