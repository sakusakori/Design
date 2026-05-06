#pragma once

// Step 1: Define the Product interface
class Shape {
public:
    virtual ~Shape() = default;

    virtual void computeArea() = 0;

    virtual void draw() = 0;
};
