#pragma once
#include <string>
using namespace std;

class Position {
private:
    int row;
    int col;

public:
    Position(int row, int col) : row(row), col(col) {}

    int getRow() { return row; }
    int getCol() { return col; }

    bool isValid() {
        return row >= 0 && row < 8 && col >= 0 && col < 8;
    }

    bool equals(Position& other) {
        return row == other.row && col == other.col;
    }

    string toString() {
        return string(1, (char)('a' + col)) + to_string(row + 1);
    }
};
