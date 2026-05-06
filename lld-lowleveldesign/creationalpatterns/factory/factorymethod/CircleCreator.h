#pragma once
#include "ShapeFactory.h"
#include "../Circle.h"

// Step 4: Concrete Creator classes
class CircleCreator : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};
