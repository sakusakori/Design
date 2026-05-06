#pragma once
#include <string>
#include "enums/PieceColour.h"
using namespace std;

class Player {
private:
    string name;
    PieceColour playingSide;

public:
    Player(string name, PieceColour playingSide)
        : name(move(name)), playingSide(playingSide) {}

    string getName() { return name; }
    void setName(string name) { this->name = move(name); }

    PieceColour getPlayingSide() { return playingSide; }
    void setPlayingSide(PieceColour side) { playingSide = side; }

    string toString() { return name; }
};
