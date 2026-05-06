#pragma once
#include <iostream>
using namespace std;

// Step 1: Abstract Product interfaces - Define product families
class CarInterior {
public:
    virtual ~CarInterior() = default;

    virtual void addInteriorComponents() = 0;
};
