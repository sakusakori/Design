#pragma once
#include <iostream>
#include <string>
using namespace std;

class File_Problem {
public:
    string fileName;

    File_Problem(string name) : fileName(move(name)) {}

    void printContents() {
        cout << "File name: " << fileName << endl;
    }
};
