#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Position.h"
#include "enums/PieceColour.h"
#include "pieces/Piece.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include "pieces/Pawn.h"
using namespace std;

class Board {
public:
    Cell cells[8][8];

    Board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cells[i][j] = Cell(nullptr, Position(i, j));
            }
        }
        initPieces();
    }

    Cell* getCell(Position position) {
        int i = position.getRow();
        int j = position.getCol();
        if (i < 0 || i > 7 || j < 0 || j > 7) {
            cout << "[ERR] Index out of bound" << endl;
            exit(0); // end game
        }
        return &cells[i][j];
    }

private:
    void initPieces() {
        // Initialize white pieces
        cells[0][0].setPiece(new Rook(WHITE));
        cells[0][1].setPiece(new Knight(WHITE));
        cells[0][2].setPiece(new Bishop(WHITE));
        cells[0][3].setPiece(new Queen(WHITE));
        cells[0][4].setPiece(new King(WHITE));
        cells[0][5].setPiece(new Bishop(WHITE));
        cells[0][6].setPiece(new Knight(WHITE));
        cells[0][7].setPiece(new Rook(WHITE));

        // Initialize white pawns
        for (int i = 0; i < 8; i++) {
            cells[1][i].setPiece(new Pawn(WHITE));
        }

        // Initialize black pieces
        cells[7][0].setPiece(new Rook(BLACK));
        cells[7][1].setPiece(new Knight(BLACK));
        cells[7][2].setPiece(new Bishop(BLACK));
        cells[7][3].setPiece(new Queen(BLACK));
        cells[7][4].setPiece(new King(BLACK));
        cells[7][5].setPiece(new Bishop(BLACK));
        cells[7][6].setPiece(new Knight(BLACK));
        cells[7][7].setPiece(new Rook(BLACK));

        // Initialize black pawns
        for (int i = 0; i < 8; i++) {
            cells[6][i].setPiece(new Pawn(BLACK));
        }
    }
};

// Deferred definitions that need Board to be complete

inline bool Piece::isPathClear(Board* board, Cell* start, Cell* end) {
    int rowDiff = end->getPosition().getRow() - start->getPosition().getRow();
    int colDiff = end->getPosition().getCol() - start->getPosition().getCol();
    int rowDir = (rowDiff > 0) ? 1 : (rowDiff < 0) ? -1 : 0;
    int colDir = (colDiff > 0) ? 1 : (colDiff < 0) ? -1 : 0;

    int currentRow = start->getPosition().getRow() + rowDir;
    int currentCol = start->getPosition().getCol() + colDir;

    while (currentRow != end->getPosition().getRow() || currentCol != end->getPosition().getCol()) {
        if (board->getCell(Position(currentRow, currentCol))->getPiece() != nullptr) {
            return false;
        }
        currentRow += rowDir;
        currentCol += colDir;
    }
    return true;
}

inline bool King::isValidMove(Board* board, Cell* start, Cell* end) {
    if (start->equals(*end)) return false;
    if (end->getPiece() != nullptr && end->getPiece()->getColour() == start->getPiece()->getColour()) return false;

    int rowDiff = abs(end->getPosition().getRow() - start->getPosition().getRow());
    int colDiff = abs(end->getPosition().getCol() - start->getPosition().getCol());
    if (rowDiff <= 1 && colDiff <= 1) {
        Piece* targetPiece = board->getCell(end->getPosition())->getPiece();
        return (targetPiece == nullptr) || targetPiece->getColour() != start->getPiece()->getColour();
    }
    return false;
}

inline bool Queen::isValidMove(Board* board, Cell* start, Cell* end) {
    if (start->equals(*end)) return false;
    if (end->getPiece() != nullptr && end->getPiece()->getColour() == start->getPiece()->getColour()) return false;

    int rowDiff = abs(end->getPosition().getRow() - start->getPosition().getRow());
    int colDiff = abs(end->getPosition().getCol() - start->getPosition().getCol());

    if ((rowDiff == 0 || colDiff == 0 || rowDiff == colDiff) && isPathClear(board, start, end)) {
        Piece* targetPiece = board->getCell(end->getPosition())->getPiece();
        return targetPiece == nullptr || targetPiece->getColour() != start->getPiece()->getColour();
    }
    return false;
}

inline bool Bishop::isValidMove(Board* board, Cell* start, Cell* end) {
    if (start->equals(*end)) return false;
    if (end->getPiece() != nullptr && end->getPiece()->getColour() == start->getPiece()->getColour()) return false;

    int rowDiff = abs(end->getPosition().getRow() - start->getPosition().getRow());
    int colDiff = abs(end->getPosition().getCol() - start->getPosition().getCol());

    if (rowDiff == colDiff && isPathClear(board, start, end)) {
        Piece* targetPiece = board->getCell(end->getPosition())->getPiece();
        return targetPiece == nullptr || targetPiece->getColour() != start->getPiece()->getColour();
    }
    return false;
}

inline bool Knight::isValidMove(Board* board, Cell* start, Cell* end) {
    if (start->equals(*end)) return false;
    if (end->getPiece() != nullptr && end->getPiece()->getColour() == start->getPiece()->getColour()) return false;

    int rowDiff = abs(end->getPosition().getRow() - start->getPosition().getRow());
    int colDiff = abs(end->getPosition().getCol() - start->getPosition().getCol());

    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
        Piece* targetPiece = board->getCell(end->getPosition())->getPiece();
        return (targetPiece == nullptr) || targetPiece->getColour() != start->getPiece()->getColour();
    }
    return false;
}

inline bool Rook::isValidMove(Board* board, Cell* start, Cell* end) {
    if (start->equals(*end)) return false;
    if (end->getPiece() != nullptr && end->getPiece()->getColour() == start->getPiece()->getColour()) return false;

    int rowDiff = abs(end->getPosition().getRow() - start->getPosition().getRow());
    int colDiff = abs(end->getPosition().getCol() - start->getPosition().getCol());

    if ((rowDiff == 0 || colDiff == 0) && isPathClear(board, start, end)) {
        Piece* targetPiece = board->getCell(end->getPosition())->getPiece();
        return targetPiece == nullptr || targetPiece->getColour() != start->getPiece()->getColour();
    }
    return false;
}

inline bool Pawn::isValidMove(Board* board, Cell* start, Cell* end) {
    if (start->equals(*end)) return false;
    if (end->getPiece() != nullptr && end->getPiece()->getColour() == start->getPiece()->getColour()) return false;

    int direction = this->getColour() == WHITE ? 1 : -1;
    int rowDiff = abs(end->getPosition().getRow() - start->getPosition().getRow());
    int colDiff = abs(end->getPosition().getCol() - start->getPosition().getCol());

    // Move forward - 1 step
    if (colDiff == 0 && rowDiff == 1) {
        return board->getCell(end->getPosition())->getPiece() == nullptr;
    }

    // First move - 2 steps
    if (colDiff == 0 && !hasMovedBefore(start) && rowDiff == 2) {
        Position intermediate(start->getPosition().getRow() + direction, start->getPosition().getCol());
        return board->getCell(intermediate)->getPiece() == nullptr && board->getCell(end->getPosition())->getPiece() == nullptr;
    }

    // Capture - diagonal
    if (colDiff == 1 && rowDiff == 1) {
        Piece* targetPiece = board->getCell(end->getPosition())->getPiece();
        return targetPiece != nullptr && targetPiece->getColour() != start->getPiece()->getColour();
    }
    return false;
}
