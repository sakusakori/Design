#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "PlayingPiece.h"
using namespace std;

class Board {
public:
    int size;
    vector<vector<PlayingPiece*>> board;

    Board(int size) : size(size) {
        board.assign(size, vector<PlayingPiece*>(size, nullptr));
    }

    bool addPiece(int row, int column, PlayingPiece* playingPiece) {
        if (board[row][column] != nullptr) {
            return false;
        }
        board[row][column] = playingPiece;
        return true;
    }

    vector<pair<int, int>> getFreeCells() {
        vector<pair<int, int>> freeCells;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == nullptr) {
                    freeCells.push_back({i, j});
                }
            }
        }

        return freeCells;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != nullptr) {
                    cout << pieceTypeName(board[i][j]->pieceType) << "   ";
                } else {
                    cout << "    ";
                }
                cout << " | ";
            }
            cout << endl;
        }
    }
};
