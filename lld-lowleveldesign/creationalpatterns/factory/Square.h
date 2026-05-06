#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;

// Step 2: Concrete Product classes
class Square : public Shape {
public:
    void computeArea() override {
        cout << "Inside Square::computeArea() method." << endl;
    }

    void draw() override {
        cout << "Inside Square::draw() method." << endl;
    }
};
