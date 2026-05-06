#pragma once
#include <iostream>
#include "ArithmeticExpression.h"
using namespace std;

// Leaf
class Number : public ArithmeticExpression {
public:
    int value;

    Number(int value) : value(value) {}

    int evaluate() override {
        cout << "Number value is: " << value << endl;
        return value;
    }
};
