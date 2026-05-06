#pragma once

// Prototype interface
class StudentPrototype {
public:
    virtual ~StudentPrototype() = default;
    virtual StudentPrototype* clone() = 0;
};
