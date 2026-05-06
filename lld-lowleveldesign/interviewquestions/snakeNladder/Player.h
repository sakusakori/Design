#pragma once
#include <string>
using namespace std;

class Player {
public:
    string id;
    int currentPosition;

    Player(string id, int currentPosition)
        : id(move(id)), currentPosition(currentPosition) {}

    // getters and setters
};
