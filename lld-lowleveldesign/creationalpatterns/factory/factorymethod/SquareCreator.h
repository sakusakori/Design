#pragma once
#include "ShapeFactory.h"
#include "../Square.h"

// Step 4: Concrete Creator classes
class SquareCreator : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};
