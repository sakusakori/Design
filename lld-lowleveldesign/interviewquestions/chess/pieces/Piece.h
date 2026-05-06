#pragma once
#include <string>
#include <cmath>
#include "../enums/PieceColour.h"
#include "../enums/PieceType.h"
#include "../Position.h"
#include "../Cell.h"
using namespace std;

class Board;

class Piece {
private:
    PieceColour colour;
    bool captured;
    PieceType pieceType;

public:
    Piece(PieceColour colour, PieceType pieceType)
        : colour(colour), captured(false), pieceType(pieceType) {}

    virtual ~Piece() = default;

    PieceColour getColour() { return colour; }
    void setColour(PieceColour colour) { this->colour = colour; }

    bool isCaptured() { return captured; }
    void setCaptured(bool captured) { this->captured = captured; }

    PieceType getPieceType() { return pieceType; }
    void setPieceType(PieceType pieceType) { this->pieceType = pieceType; }

    bool isPathClear(Board* board, Cell* start, Cell* end);

    virtual bool isValidMove(Board* board, Cell* start, Cell* end) = 0;

    string toString() {
        string symbol;
        switch (pieceType) {
            case KING:   symbol = "K"; break;
            case QUEEN:  symbol = "Q"; break;
            case ROOK:   symbol = "R"; break;
            case BISHOP: symbol = "B"; break;
            case KNIGHT: symbol = "N"; break;
            case PAWN:   symbol = "P"; break;
        }
        if (colour == BLACK) {
            symbol[0] = symbol[0] + 32; // toLowerCase
        }
        return symbol;
    }
};
