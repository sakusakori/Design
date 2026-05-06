#pragma once
#include <string>
#include "Position.h"
using namespace std;

class Piece; // forward declaration

class Cell {
private:
    Piece* piece;
    Position position;

public:
    Cell() : piece(nullptr), position(0, 0) {}
    Cell(Piece* piece, Position position) : piece(piece), position(position) {}

    Piece* getPiece() { return piece; }
    void setPiece(Piece* piece) { this->piece = piece; }

    Position& getPosition() { return position; }
    void setPosition(Position position) { this->position = position; }

    bool equals(Cell& other) {
        return position.equals(other.position);
    }
};
