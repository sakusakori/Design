#pragma once
#include <cmath>
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(PieceColour colour) : Piece(colour, ROOK) {}

    bool isValidMove(Board* board, Cell* start, Cell* end) override;
};
