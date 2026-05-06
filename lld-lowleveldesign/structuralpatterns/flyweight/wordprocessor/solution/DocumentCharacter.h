#pragma once
#include <iostream>
#include <string>
#include "ILetter.h"
using namespace std;

// Concrete Flyweight (Class) - implements the Flyweight interface and stores intrinsic state
class DocumentCharacter : public ILetter {
private:
    // intrinsic data - shared data - common to all objects
    char character;
    string fontType;
    int size;

public:
    DocumentCharacter(char character, string fontType, int size)
        : character(character), fontType(move(fontType)), size(size) {}

    // getter methods only

    void display(int row, int column) override {
        //display the character of particular font and size at given location
        cout << "Displaying " << character << " at row " << row << " and column " << column << endl;
    }
};
