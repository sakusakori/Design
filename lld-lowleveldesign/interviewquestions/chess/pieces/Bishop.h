#pragma once
#include <cmath>
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(PieceColour colour) : Piece(colour, BISHOP) {}

    bool isValidMove(Board* board, Cell* start, Cell* end) override;
};
