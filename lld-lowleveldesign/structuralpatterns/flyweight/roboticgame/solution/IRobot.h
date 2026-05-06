#pragma once

// Flyweight (Interface) - for the flyweight object - defines methods that use extrinsic state.
class IRobot {
public:
    virtual ~IRobot() = default;
    // CoordinateX and CoordinateY are extrinsic data - unique to each object
    virtual void display(int x, int y) = 0;
};
