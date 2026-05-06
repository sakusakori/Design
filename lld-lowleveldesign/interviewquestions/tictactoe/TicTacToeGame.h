#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include "model/Board.h"
#include "model/Player.h"
#include "model/PlayingPieceX.h"
#include "model/PlayingPieceO.h"
#include "model/GameStatus.h"
using namespace std;

class TicTacToeGame {
public:
    deque<Player*> players;
    Board* gameBoard;
    Player* winner = nullptr;

    PlayingPieceX crossPiece;
    PlayingPieceO noughtsPiece;
    Player player1;
    Player player2;

    TicTacToeGame()
        : gameBoard(nullptr),
          player1("Player1", &crossPiece),
          player2("Player2", &noughtsPiece) {}

    ~TicTacToeGame() {
        delete gameBoard;
    }

    void initializeGame() {
        // Creating 2 Players
        players.push_back(&player1);
        players.push_back(&player2);

        // Initialize Board of size 3
        gameBoard = new Board(3);
    }

    GameStatus startGame() {
        bool noWinner = true;
        while (noWinner) {

            // Remove the player whose turn is and also put the player in the list back
            Player* currentPlayer = players.front();
            players.pop_front();

            // Get the free space from the board
            gameBoard->printBoard();
            vector<pair<int, int>> freeSpaces = gameBoard->getFreeCells();
            if (freeSpaces.empty()) {
                noWinner = false;
                continue;
            }

            // Read the user input
            cout << "Player: " << currentPlayer->name << " - Please enter [row, column]: ";
            string s;
            getline(cin, s);
            stringstream ss(s);
            string token;
            getline(ss, token, ',');
            int inputRow = stoi(token);
            getline(ss, token, ',');
            int inputColumn = stoi(token);

            // Place the piece in the board
            bool validMove = gameBoard->addPiece(inputRow, inputColumn, currentPlayer->playingPiece);
            if (!validMove) {
                // Invalid Move: Player can not insert the piece into this cell, player has to choose another cell
                cout << "Incorrect position chosen, try again!" << endl;
                players.push_front(currentPlayer); // Add the player back to the queue(in the front)
                continue;
            }
            players.push_back(currentPlayer); // Add the player to the end of the queue

            // Check if the valid move is a winning move or not
            bool isWinner = checkForWinner(inputRow, inputColumn, currentPlayer->playingPiece->pieceType);
            if (isWinner) {
                gameBoard->printBoard();
                winner = currentPlayer;
                return WIN;
            }
        }

        return DRAW;
    }

    bool checkForWinner(int row, int column, PieceType pieceType) {

        bool rowMatch = true;
        bool columnMatch = true;
        bool diagonalMatch = true;
        bool antiDiagonalMatch = true;

        // Check Row
        for (int i = 0; i < gameBoard->size; i++) {
            if (gameBoard->board[row][i] == nullptr || gameBoard->board[row][i]->pieceType != pieceType) {
                rowMatch = false;
                break;
            }
        }

        // Check Column
        for (int i = 0; i < gameBoard->size; i++) {
            if (gameBoard->board[i][column] == nullptr || gameBoard->board[i][column]->pieceType != pieceType) {
                columnMatch = false;
                break;
            }
        }

        // Check Diagonally
        for (int i = 0, j = 0; i < gameBoard->size; i++, j++) {
            if (gameBoard->board[i][j] == nullptr || gameBoard->board[i][j]->pieceType != pieceType) {
                diagonalMatch = false;
                break;
            }
        }

        // Check Anti-Diagonally
        for (int i = 0, j = gameBoard->size - 1; i < gameBoard->size; i++, j--) {
            if (gameBoard->board[i][j] == nullptr || gameBoard->board[i][j]->pieceType != pieceType) {
                antiDiagonalMatch = false;
                break;
            }
        }

        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
    }
};
