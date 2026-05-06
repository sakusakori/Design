#include <iostream>
#include "../ShapeType.h"
#include "ShapeFactory.h"
#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "SquareCreator.h"
using namespace std;

Shape* getShapeInstance(ShapeType shapeType) {
    Shape* shape = nullptr;
    switch (shapeType) {
        case CIRCLE: {
            CircleCreator circleCreator;
            shape = circleCreator.createShape();
            break;
        }
        case RECTANGLE: {
            RectangleCreator rectangleCreator;
            shape = rectangleCreator.createShape();
            break;
        }
        case SQUARE: {
            SquareCreator squareCreator;
            shape = squareCreator.createShape();
            break;
        }
        default:
            throw invalid_argument("ShapeType doesn't exist.");
    }
    return shape;
}

// Step 5: Client code demonstration
int main() {
    cout << "======= Factory Method Design Pattern ======" << endl;

    // set the type you want
    ShapeType shapeType = SQUARE;
    // get the shape
    Shape* shape = getShapeInstance(shapeType);
    // perform operations
    shape->draw();
    shape->computeArea();

    delete shape;
    return 0;
}
