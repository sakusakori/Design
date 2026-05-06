#include <iostream>
#include "strategies/SportsDrive.h"
#include "strategies/NormalDrive.h"
#include "strategies/EVDrive.h"
#include "context/SportsVehicle.h"
#include "context/GoodsVehicle.h"
#include "context/HybridVehicle.h"
using namespace std;

int main() {
    cout << "###### Strategy Design Pattern ######" << endl;
    cout << "###### Example: Vehicle Drive Modes ######" << endl;

    SportsDrive sportsDrive;
    NormalDrive normalDrive;
    EVDrive evDrive;

    SportsVehicle sports(&sportsDrive);
    sports.drive();

    GoodsVehicle goods(&normalDrive);
    goods.drive();

    HybridVehicle hybrid(&evDrive);
    hybrid.drive();

    GoodsVehicle goods2(&normalDrive);
    goods2.drive();

    return 0;
}
