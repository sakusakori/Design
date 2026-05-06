#include <iostream>
#include "ShapeFactory.h"
using namespace std;

// Step 3: Simple Factory Demo (Bloated Design)
int main() {
    cout << "======= Simple Factory Design Pattern ======" << endl;

    // set the type you want
    ShapeType shapeType = SQUARE;
    // get the shape
    Shape* shape = ShapeFactory::createShape(shapeType);
    shape->draw();
    shape->computeArea();

    delete shape;
    return 0;
}
