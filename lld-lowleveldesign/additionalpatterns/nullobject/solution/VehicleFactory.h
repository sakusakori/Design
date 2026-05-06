#pragma once
#include <string>
#include "../Vehicle.h"
#include "../Car.h"
#include "../Bike.h"
#include "NullVehicle.h"
using namespace std;

class VehicleFactory_Solution {
public:
    static Vehicle* getVehicle(string type) {
        if (type == "car") {
            return new Car("Toyota", "Red", 5, 60, true);
        } else if (type == "bike") {
            return new Bike("Yamaha", "Black", 60);
        } else {
            return new NullVehicle(); // THE SOLUTION
        }
    }
};
