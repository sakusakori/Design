#pragma once
#include <vector>
#include <cstdlib>
#include "Cell.h"
#include "Jump.h"
using namespace std;

class Board {
public:
    vector<vector<Cell>> cells;

    Board(int boardSize, int numberOfSnakes, int numberOfLadders) {
        initializeCells(boardSize);
        addSnakesLadders(numberOfSnakes, numberOfLadders);
    }

private:
    void initializeCells(int boardSize) {
        cells.assign(boardSize, vector<Cell>(boardSize));
    }

    void addSnakesLadders(int numberOfSnakes, int numberOfLadders) {

        int totalCells = cells.size() * cells.size();

        while (numberOfSnakes > 0) {
            int snakeHead = 1 + (rand() % (totalCells - 2));
            int snakeTail = 1 + (rand() % (totalCells - 2));
            if (snakeTail >= snakeHead) {
                continue;
            }

            Jump* snakeObj = new Jump();
            snakeObj->start = snakeHead;
            snakeObj->end = snakeTail;

            Cell& cell = getCell(snakeHead);
            cell.jump = snakeObj;

            numberOfSnakes--;
        }

        while (numberOfLadders > 0) {
            int ladderStart = 1 + (rand() % (totalCells - 2));
            int ladderEnd = 1 + (rand() % (totalCells - 2));
            if (ladderStart >= ladderEnd) {
                continue;
            }

            Jump* ladderObj = new Jump();
            ladderObj->start = ladderStart;
            ladderObj->end = ladderEnd;

            Cell& cell = getCell(ladderStart);
            cell.jump = ladderObj;

            numberOfLadders--;
        }
    }

public:
    Cell& getCell(int playerPosition) {
        int boardRow = playerPosition / cells.size();
        int boardColumn = playerPosition % cells.size();
        return cells[boardRow][boardColumn];
    }
};
