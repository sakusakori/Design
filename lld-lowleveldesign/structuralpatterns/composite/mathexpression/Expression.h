#pragma once
#include <iostream>
#include "ArithmeticExpression.h"
#include "OperationType.h"
using namespace std;

// Composite
class Expression : public ArithmeticExpression {
public:
    ArithmeticExpression* leftExpression;
    ArithmeticExpression* rightExpression;
    OperationType operation;

    Expression(ArithmeticExpression* leftPart, ArithmeticExpression* rightPart, OperationType operation)
        : leftExpression(leftPart), rightExpression(rightPart), operation(operation) {}

    int evaluate() override {
        int value = 0;
        switch (operation) {
            case ADD:
                value = leftExpression->evaluate() + rightExpression->evaluate();
                break;
            case SUBTRACT:
                value = leftExpression->evaluate() - rightExpression->evaluate();
                break;
            case DIVIDE:
                value = leftExpression->evaluate() / rightExpression->evaluate();
                break;
            case MULTIPLY:
                value = leftExpression->evaluate() * rightExpression->evaluate();
                break;
        }

        cout << "Expression value is:" << value << endl;
        return value;
    }
};
