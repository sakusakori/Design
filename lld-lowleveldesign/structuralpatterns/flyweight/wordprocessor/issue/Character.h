#pragma once
#include <string>
using namespace std;

class Character {
public:
    char character;
    string fontType;
    int size;
    int row;
    int column;

    Character(char character, string fontType, int size, int row, int column)
        : character(character), fontType(move(fontType)), size(size), row(row), column(column) {}
};
