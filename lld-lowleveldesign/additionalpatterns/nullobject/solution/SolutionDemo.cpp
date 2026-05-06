#include <iostream>
#include "VehicleFactory.h"
#include "../Car.h"
#include "../Bike.h"
using namespace std;

void printVehicleDetails_Solution(Vehicle* vehicle) {
    Car* car = dynamic_cast<Car*>(vehicle);
    if (car != nullptr) {
        cout << "\n[+] Vehicle Details: Car"
             << " [Model=" << car->getModel()
             << ", Color=" << car->getColor()
             << ", Seating Capacity=" << car->getSeatingCapacity()
             << ", Fuel Tank Capacity=" << car->getFuelTankCapacity() << "]" << endl;
    }
    Bike* bike = dynamic_cast<Bike*>(vehicle);
    if (bike != nullptr) {
        cout << "\n[+] Vehicle Details: Bike"
             << " [Model=" << bike->getModel()
             << ", Color=" << bike->getColor()
             << ", Fuel Tank Capacity=" << bike->getFuelTankCapacity() << "]" << endl;
    }
}

void testDrive_Solution(Vehicle* vehicle) {
    // No null check needed! NullVehicle handles it gracefully
    vehicle->start();
    vehicle->stop();
}

int main() {
    cout << "\n##### Null Object Pattern: Solution Demo #####" << endl;

    Vehicle* car = VehicleFactory_Solution::getVehicle("car");
    printVehicleDetails_Solution(car);
    testDrive_Solution(car);

    Vehicle* bike = VehicleFactory_Solution::getVehicle("bike");
    printVehicleDetails_Solution(bike);
    testDrive_Solution(bike);

    // No null check needed! NullVehicle provides safe do-nothing behavior
    Vehicle* nullVehicle = VehicleFactory_Solution::getVehicle("null");
    printVehicleDetails_Solution(nullVehicle);
    testDrive_Solution(nullVehicle);

    delete car;
    delete bike;
    delete nullVehicle;

    return 0;
}
