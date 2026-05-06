#pragma once

// Flyweight (Interface) - for the flyweight object - defines methods that use extrinsic state.
class ILetter {
public:
    virtual ~ILetter() = default;
    // The position(row,column) is extrinsic data - unique to each object
    virtual void display(int row, int column) = 0;
};
