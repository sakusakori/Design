#pragma once
#include <string>
#include "Sprites.h"
using namespace std;

// Robot class - Used to create Humanoid and Robotic Dog robots
class Robot {
public:
    // extrinsic data
    int coordinateX;
    int coordinateY;
    // intrinsic data
    string type;
    Sprites_Issue* body; // heavy-weight object - 2D bitmap image

    Robot(int coordinateX, int coordinateY, string type, Sprites_Issue* body)
        : coordinateX(coordinateX), coordinateY(coordinateY),
          type(move(type)), body(body) {}
    // getters and setters
};
