#pragma once
#include <iostream>
#include <string>
#include "FileSystemComponent.h"
using namespace std;

// Step 2: Leaf - File
class File : public FileSystemComponent {
public:
    string fileName;

    File(string name) : fileName(move(name)) {}

    void printContents() override {
        cout << "File name: " << fileName << endl;
    }
};
