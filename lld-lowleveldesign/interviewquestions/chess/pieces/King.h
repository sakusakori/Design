#pragma once
#include <cmath>
#include "Piece.h"

class King : public Piece {
public:
    King(PieceColour colour) : Piece(colour, KING) {}

    bool isValidMove(Board* board, Cell* start, Cell* end) override;
};
