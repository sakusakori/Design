#include <iostream>
#include "Vehicle.h"
#include "SportsVehicle.h"
#include "OffRoadVehicle.h"
#include "PassengerVehicle.h"
using namespace std;

int main() {
    cout << "Vehicle Drive Modes: Problem Demo" << endl;

    SportsVehicle_Problem sports;
    sports.drive();

    OffRoadVehicle_Problem offRoad;
    offRoad.drive();

    PassengerVehicle_Problem passenger;
    passenger.drive();

    return 0;
}
