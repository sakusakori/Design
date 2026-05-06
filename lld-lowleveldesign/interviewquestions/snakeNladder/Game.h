#pragma once
#include <iostream>
#include <deque>
#include <string>
#include "Board.h"
#include "Dice.h"
#include "Player.h"
using namespace std;

class Game {
public:
    Board* board;
    Dice* dice;
    deque<Player*> playersList;
    Player* winner;

    Player player1;
    Player player2;

    Game()
        : board(nullptr), dice(nullptr), winner(nullptr),
          player1("Player-1", 0), player2("Player-2", 0) {
        initializeGame();
    }

    ~Game() {
        delete board;
        delete dice;
    }

    void startGame() {
        int totalCells = board->cells.size() * board->cells.size();

        while (winner == nullptr) {
            //check whose turn now
            Player* playerTurn = findPlayerTurn();
            cout << "Player turn:" << playerTurn->id
                 << " current position is: " << playerTurn->currentPosition << endl;

            //roll the dice
            int diceNumbers = dice->rollDice();

            //get the new position
            int playerNewPosition = playerTurn->currentPosition + diceNumbers;
            playerNewPosition = jumpCheck(playerNewPosition);
            playerTurn->currentPosition = playerNewPosition;

            cout << "Player turn:" << playerTurn->id
                 << " new Position is: " << playerNewPosition << endl;

            //check for winning condition
            if (playerNewPosition >= totalCells - 1) {
                winner = playerTurn;
            }
        }
        cout << "\n===> The Winner is:" << winner->id << endl;
    }

private:
    void initializeGame() {
        board = new Board(10, 5, 4);
        dice = new Dice(1);
        winner = nullptr;
        addPlayers();
    }

    void addPlayers() {
        playersList.push_back(&player1);
        playersList.push_back(&player2);
    }

    Player* findPlayerTurn() {
        Player* playerTurns = playersList.front();
        playersList.pop_front();
        playersList.push_back(playerTurns);
        return playerTurns;
    }

    int jumpCheck(int playerNewPosition) {
        int totalCells = board->cells.size() * board->cells.size();

        if (playerNewPosition > totalCells - 1) {
            return playerNewPosition;
        }

        Cell& cell = board->getCell(playerNewPosition);
        if (cell.jump != nullptr && cell.jump->start == playerNewPosition) {
            string jumpBy = (cell.jump->start < cell.jump->end) ? "Ladder" : "Snake";
            cout << "[+] Jump done by: " << jumpBy << endl;
            return cell.jump->end;
        }
        return playerNewPosition;
    }
};
