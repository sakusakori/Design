#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;

// Step 2: Concrete Product classes
class Rectangle : public Shape {
public:
    void computeArea() override {
        cout << "Inside Rectangle::computeArea() method." << endl;
    }

    void draw() override {
        cout << "Inside Rectangle::draw() method." << endl;
    }
};
