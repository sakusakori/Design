#pragma once

class Vehicle {
public:
    virtual ~Vehicle() = default;

    virtual void start() = 0;

    virtual void stop() = 0;
};
