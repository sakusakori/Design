#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;

// Step 2: Concrete Product classes
class Circle : public Shape {
public:
    void computeArea() override {
        cout << "Inside Circle::computeArea() method." << endl;
    }

    void draw() override {
        cout << "Inside Circle::draw() method." << endl;
    }
};
