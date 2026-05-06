#pragma once
#include <string>
#include "Cell.h"
#include "Player.h"
#include "pieces/Piece.h"
using namespace std;

class Move {
private:
    Player* player;
    Cell* start;
    Cell* end;
    Piece* pieceMoved;
    Piece* pieceKilled;

public:
    Move(Player* player, Cell* start, Cell* end)
        : player(player), start(start), end(end),
          pieceMoved(start->getPiece()), pieceKilled(nullptr) {}

    Player* getPlayer() { return player; }
    void setPlayer(Player* player) { this->player = player; }

    Cell* getStart() { return start; }
    void setStart(Cell* start) { this->start = start; }

    Cell* getEnd() { return end; }
    void setEnd(Cell* end) { this->end = end; }

    Piece* getPieceMoved() { return pieceMoved; }
    void setPieceMoved(Piece* piece) { pieceMoved = piece; }

    Piece* getPieceKilled() { return pieceKilled; }
    void setPieceKilled(Piece* piece) { pieceKilled = piece; }
};
