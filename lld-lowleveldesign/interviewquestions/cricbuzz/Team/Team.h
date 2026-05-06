#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Player/PlayerDetails.h"
#include "Player/PlayerBattingController.h"
#include "Player/PlayerBowlingController.h"
using namespace std;

class Team {
public:
    string teamName;
    queue<PlayerDetails*> playing11;
    vector<PlayerDetails*> playing11List; // for iteration
    vector<PlayerDetails*> bench;
    PlayerBattingController* battingController;
    PlayerBowlingController* bowlingController;
    bool isWinner;

    Team(string teamName, queue<PlayerDetails*> playing11, vector<PlayerDetails*> bench, vector<PlayerDetails*> bowlers)
        : teamName(move(teamName)), playing11(playing11), bench(move(bench)), isWinner(false) {
        // store a list copy for iteration
        queue<PlayerDetails*> temp = playing11;
        while (!temp.empty()) {
            playing11List.push_back(temp.front());
            temp.pop();
        }
        battingController = new PlayerBattingController(playing11);
        bowlingController = new PlayerBowlingController(bowlers);
    }

    string getTeamName() { return teamName; }

    void chooseNextBatsMan() {
        battingController->getNextPlayer();
    }

    void chooseNextBowler(int maxOverCountPerBowler) {
        bowlingController->getNextBowler(maxOverCountPerBowler);
    }

    PlayerDetails* getStriker() { return battingController->getStriker(); }
    void setStriker(PlayerDetails* player) { battingController->setStriker(player); }

    PlayerDetails* getNonStriker() { return battingController->getNonStriker(); }
    void setNonStriker(PlayerDetails* player) { battingController->setNonStriker(player); }

    PlayerDetails* getCurrentBowler() { return bowlingController->getCurrentBowler(); }

    void printBattingScoreCard() {
        for (PlayerDetails* p : playing11List) {
            p->printBattingScoreCard();
        }
    }

    void printBowlingScoreCard() {
        for (PlayerDetails* p : playing11List) {
            if (p->bowlingScoreCard->totalOversCount > 0) {
                p->printBowlingScoreCard();
            }
        }
    }

    int getTotalRuns() {
        int totalRun = 0;
        for (PlayerDetails* player : playing11List) {
            totalRun += player->battingScoreCard->totalRuns;
        }
        return totalRun;
    }
};
