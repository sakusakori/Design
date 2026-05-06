#include <iostream>
#include "AirConditioner.h"
#include "Bulb.h"
using namespace std;

int main() {
    cout << "##### Command Pattern: Problem Demo #####" << endl;

    // Device: Air Conditioner Commands
    AirConditioner_Problem airConditioner;
    airConditioner.turnOn();
    airConditioner.setTemperature(25);
    airConditioner.turnOff();

    // Device: Bulb Commands
    Bulb bulb;
    bulb.turnOn();
    bulb.turnOff();

    return 0;
}
