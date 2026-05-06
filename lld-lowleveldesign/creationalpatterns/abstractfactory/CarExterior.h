#pragma once
#include <iostream>
using namespace std;

// Step 1: Abstract Product interfaces - Define product families
class CarExterior {
public:
    virtual ~CarExterior() = default;

    virtual void addExteriorComponents() = 0;
};
