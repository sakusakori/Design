#pragma once
#include "../Shape.h"

// Step 3: Abstract Creator class
class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;

    // Factory method - to be implemented by subclasses
    virtual Shape* createShape() = 0;
};
