#pragma once

// Strategy interface - defines the contract for drive behavior
class DriveStrategy {
public:
    virtual ~DriveStrategy() = default;
    virtual void drive() = 0;
};
