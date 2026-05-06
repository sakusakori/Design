#pragma once
#include <deque>
#include <map>
#include <vector>
#include "PlayerDetails.h"
using namespace std;

class PlayerBowlingController {
public:
    deque<PlayerDetails*> bowlersList;
    map<PlayerDetails*, int> bowlerVsOverCount;
    PlayerDetails* currentBowler;

    PlayerBowlingController(vector<PlayerDetails*>& bowlers) : currentBowler(nullptr) {
        for (PlayerDetails* bowler : bowlers) {
            bowlersList.push_back(bowler);
            bowlerVsOverCount[bowler] = 0;
        }
    }

    void getNextBowler(int maxOverCountPerBowler) {
        PlayerDetails* playerDetails = bowlersList.front();
        bowlersList.pop_front();

        if (bowlerVsOverCount[playerDetails] + 1 == maxOverCountPerBowler) {
            currentBowler = playerDetails;
        } else {
            currentBowler = playerDetails;
            bowlersList.push_back(playerDetails);
            bowlerVsOverCount[playerDetails] = bowlerVsOverCount[playerDetails] + 1;
        }
    }

    PlayerDetails* getCurrentBowler() { return currentBowler; }
};
