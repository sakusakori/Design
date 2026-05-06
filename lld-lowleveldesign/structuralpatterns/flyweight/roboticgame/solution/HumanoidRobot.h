#pragma once
#include <iostream>
#include <string>
#include "IRobot.h"
#include "Sprites.h"
using namespace std;

// Concrete Flyweight (Class) - implements the Flyweight interface and stores intrinsic state.
class HumanoidRobot : public IRobot {
private:
    // intrinsic data - shared data - common to all objects
    string type; // humanoid or robotic dog
    Sprites* body; //small 2d bitmap (graphic element)

public:
    HumanoidRobot(string type, Sprites* body)
        : type(move(type)), body(body) {}

    string getType() { return type; }
    Sprites* getBody() { return body; }

    void display(int x, int y) override {
        // use the humanoid sprites object
        // and X and Y coordinate to render the image.
        cout << "Displaying " << type << " at " << x << ", " << y << endl;
    }
};
