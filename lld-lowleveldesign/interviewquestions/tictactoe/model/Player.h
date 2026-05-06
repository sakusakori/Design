#pragma once
#include <string>
#include "PlayingPiece.h"
using namespace std;

class Player {
public:
    string name;
    PlayingPiece* playingPiece;

    Player(string name, PlayingPiece* playingPiece)
        : name(move(name)), playingPiece(playingPiece) {}

    string getName() { return name; }
    void setName(string name) { this->name = move(name); }

    PlayingPiece* getPlayingPiece() { return playingPiece; }
    void setPlayingPiece(PlayingPiece* playingPiece) { this->playingPiece = playingPiece; }
};
