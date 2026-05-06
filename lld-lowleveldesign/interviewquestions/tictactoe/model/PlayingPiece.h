#pragma once
#include "PieceType.h"

class PlayingPiece {
public:
    PieceType pieceType;

    PlayingPiece(PieceType pieceType) : pieceType(pieceType) {}
};
