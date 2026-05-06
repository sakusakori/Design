#pragma once
#include "../Shape.h"
#include "../ShapeType.h"
#include "../Circle.h"
#include "../Rectangle.h"
#include "../Square.h"
#include <stdexcept>

class ShapeFactory {
public:
    static Shape* createShape(ShapeType shapeType) {
        switch (shapeType) {
            case CIRCLE:    return new Circle();
            case RECTANGLE: return new Rectangle();
            case SQUARE:    return new Square();
            default:        throw invalid_argument("ShapeType doesn't exist.");
        }
    }
};
