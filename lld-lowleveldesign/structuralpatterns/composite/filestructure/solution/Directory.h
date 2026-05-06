#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "FileSystemComponent.h"
using namespace std;

// Step 3: Composite - Folder
class Directory : public FileSystemComponent {
public:
    string directoryName;
    vector<FileSystemComponent*> children;

    Directory(string name) : directoryName(move(name)) {}

    void add(FileSystemComponent* component) {
        children.push_back(component);
    }

    void remove(FileSystemComponent* component) {
        auto it = find(children.begin(), children.end(), component);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    void printContents() override {
        cout << "Directory Name: " << directoryName << endl;
        for (FileSystemComponent* child : children) {
            child->printContents();
        }
    }
};
