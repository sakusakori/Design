#include <iostream>
#include "VehicleFactory.h"
#include "../Car.h"
#include "../Bike.h"
using namespace std;

void printVehicleDetails_Problem(Vehicle* vehicle) {
    if (vehicle != nullptr) {
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
}

void testDrive_Problem(Vehicle* vehicle) {
    if (vehicle != nullptr) {
        vehicle->start();
        vehicle->stop();
    }
}

int main() {
    cout << "\n##### Null Object Pattern: Problem Demo #####" << endl;

    Vehicle* car = VehicleFactory_Problem::getVehicle("car");
    printVehicleDetails_Problem(car);
    testDrive_Problem(car);

    Vehicle* bike = VehicleFactory_Problem::getVehicle("bike");
    printVehicleDetails_Problem(bike);
    testDrive_Problem(bike);

    // Saved by NULL Check in printVehicleDetails and testDrive methods
    // Without NULL Check, it would crash with segfault
    Vehicle* nullVehicle = VehicleFactory_Problem::getVehicle("null");
    printVehicleDetails_Problem(nullVehicle);
    testDrive_Problem(nullVehicle);

    delete car;
    delete bike;
    // nullVehicle is nullptr, no delete needed

    return 0;
}
