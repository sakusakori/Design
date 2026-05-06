#pragma once
#include "ShapeFactory.h"
#include "../Rectangle.h"

// Step 4: Concrete Creator classes
class RectangleCreator : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Rectangle();
    }
};
