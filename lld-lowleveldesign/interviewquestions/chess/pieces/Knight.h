#pragma once
#include <cmath>
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(PieceColour colour) : Piece(colour, KNIGHT) {}

    bool isValidMove(Board* board, Cell* start, Cell* end) override;
};
