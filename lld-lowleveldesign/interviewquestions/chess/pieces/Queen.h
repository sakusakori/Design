#pragma once
#include <cmath>
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(PieceColour colour) : Piece(colour, QUEEN) {}

    bool isValidMove(Board* board, Cell* start, Cell* end) override;
};
