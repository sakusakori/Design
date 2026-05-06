#include <iostream>
#include "RoboticFactory.h"
using namespace std;

// Client - supplies extrinsic state when using flyweights
int main() {
    cout << "====== Flyweight Design Pattern ======" << endl;
    // Factory pattern is used to create objects
    // Flyweight pattern is used to reuse objects

    // Create 2 Humanoid robots and provide display coordinates(extrinsic state) at runtime
    IRobot* humanoidRobot1 = RoboticFactory::createRobot("HUMANOID");
    humanoidRobot1->display(1, 2);
    IRobot* humanoidRobot2 = RoboticFactory::createRobot("HUMANOID");
    humanoidRobot2->display(10, 30);

    // Create 2 Robotic Dog robots and provide display coordinates(extrinsic state) at runtime
    IRobot* roboDog1 = RoboticFactory::createRobot("ROBOTIC_DOG");
    roboDog1->display(2, 9);
    IRobot* roboDog2 = RoboticFactory::createRobot("ROBOTIC_DOG");
    roboDog2->display(11, 19);

    // Total robots created: 2 - because we are reusing the same object
    cout << "Total robots created: " << RoboticFactory::getTotalRobots() << endl;

    return 0;
}
