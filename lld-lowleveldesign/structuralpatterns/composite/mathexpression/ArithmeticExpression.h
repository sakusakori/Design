#pragma once

// Component Interface
class ArithmeticExpression {
public:
    virtual ~ArithmeticExpression() = default;

    virtual int evaluate() = 0;
};
