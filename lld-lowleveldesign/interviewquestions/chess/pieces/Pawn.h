#pragma once
#include <cmath>
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(PieceColour colour) : Piece(colour, PAWN) {}

    bool isValidMove(Board* board, Cell* start, Cell* end) override;

private:
    bool hasMovedBefore(Cell* start) {
        return start->getPosition().getRow() != 1 && start->getPosition().getRow() != 6;
    }
};
