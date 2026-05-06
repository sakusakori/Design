#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "File.h"
using namespace std;

class Directory_Problem {
public:
    string directoryName;
    // Using void* to mimic Java's List<Object> - this is the PROBLEM
    vector<void*> objectList;
    vector<bool> isDirectory; // track type manually - ugly!

    Directory_Problem(string name) : directoryName(move(name)) {}

    void addFile(File_Problem* file) {
        objectList.push_back(file);
        isDirectory.push_back(false);
    }

    void addDirectory(Directory_Problem* dir) {
        objectList.push_back(dir);
        isDirectory.push_back(true);
    }

    // Breaks OCP - if we want to add a new file type, we need to modify this method
    void printContents() {
        cout << "Directory Name: " << directoryName << endl;
        for (int i = 0; i < (int)objectList.size(); i++) {
            if (isDirectory[i]) {
                ((Directory_Problem*)objectList[i])->printContents();
            } else {
                ((File_Problem*)objectList[i])->printContents();
            }
        }
    }
};
