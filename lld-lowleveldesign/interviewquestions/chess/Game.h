#pragma once
#include <iostream>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Move.h"
#include "enums/GameStatus.h"
#include "enums/PieceColour.h"
#include "pieces/King.h"
using namespace std;

class Game {
private:
    Player* player1;
    Player* player2;
    Board* board;
    Player* currentTurn;
    GameStatus status;
    vector<Move*> movesHistory;

public:
    Game(Player* player1, Player* player2)
        : player1(player1), player2(player2), status(IN_PROGRESS) {
        board = new Board();
        if (player1->getPlayingSide() == WHITE)
            currentTurn = player1;
        else
            currentTurn = player2;
    }

    bool playMove(Player* player, Position start, Position end) {
        Cell* startCell = board->getCell(start);
        Cell* endCell = board->getCell(end);
        Move* move = new Move(player, startCell, endCell);
        return makeMove(move, player);
    }

    GameStatus getStatus() { return status; }
    void setStatus(GameStatus s) { status = s; }

    Board* getBoard() { return board; }
    void setBoard(Board* b) { board = b; }

    void displayMovesHistory() {
        for (Move* move : movesHistory) {
            cout << "Move [player=" << move->getPlayer()->toString()
                 << ", pieceMoved=" << (move->getPieceMoved() ? move->getPieceMoved()->toString() : "null")
                 << ", pieceKilled=" << (move->getPieceKilled() ? move->getPieceKilled()->toString() : "null")
                 << "]" << endl;
        }
    }

    void display() {
        cout << "\nCurrent turn: " << currentTurn->toString() << endl;
        cout << "Game status: " << gameStatusName(status) << endl;
    }

private:
    bool makeMove(Move* move, Player* player) {
        Piece* startPiece = move->getStart()->getPiece();
        Piece* endPiece = move->getEnd()->getPiece();

        if (startPiece == nullptr) return false;
        if (startPiece->getColour() != player->getPlayingSide()) return false;
        if (!startPiece->isValidMove(board, move->getStart(), move->getEnd())) return false;

        if (endPiece != nullptr) {
            endPiece->setCaptured(true);
            move->setPieceKilled(endPiece);
        }

        move->setPieceMoved(startPiece);
        move->getEnd()->setPiece(startPiece);
        move->getStart()->setPiece(nullptr);

        movesHistory.push_back(move);

        if (dynamic_cast<King*>(endPiece) != nullptr) {
            cout << "\n===>>> Its a Checkmate!!!" << endl;
            if (player->getPlayingSide() == WHITE) {
                setStatus(WHITE_WIN);
                cout << "===>>> Game Status: " << gameStatusName(getStatus()) << endl;
            } else {
                setStatus(BLACK_WIN);
                cout << "===>>> Game Status: " << gameStatusName(getStatus()) << endl;
            }
        }

        if (currentTurn == player1) currentTurn = player2;
        else currentTurn = player1;

        return true;
    }
};
