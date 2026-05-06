#include <iostream>
#include "Robot.h"
#include "Sprites.h"
using namespace std;

// Client Code - Robotic game creating robots
int main() {
    int x = 0;
    int y = 0;
    // Create 5L Humanoid robots
    for (int i = 0; i < 500000; i++) {
        Sprites_Issue* humanoidSprite = new Sprites_Issue();
        Robot* humanoidRobotObject = new Robot(x + i, y + i, "HUMANOID", humanoidSprite);
    }
    // Create 50L Robotic Dog robots
    for (int i = 0; i < 500000; i++) {
        Sprites_Issue* roboticDogSprite = new Sprites_Issue();
        Robot* roboticDogObject = new Robot(x + i, y + i, "ROBOTIC_DOGS", roboticDogSprite);
    }
    // A total of 10L robots created will result in 10L Sprite objects created
    // which will consume a lot of memory.

    return 0;
}
