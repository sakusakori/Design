#include <iostream>
#include "AirConditioner.h"
#include "RemoteController.h"
#include "TurnOnCommand.h"
#include "TurnOffCommand.h"
#include "SetTemperatureCommand.h"
using namespace std;

// Client - Demonstration
int main() {
    cout << "##### Command Pattern: Solution Demo #####" << endl;

    // Create Receiver
    AirConditioner airConditioner;

    // Create Invoker
    RemoteController remoteObj;

    // Execute Commands
    TurnOnCommand turnOn(&airConditioner);
    remoteObj.setCommand(&turnOn);
    remoteObj.pressButton();

    SetTemperatureCommand setTemp25(&airConditioner, 25);
    remoteObj.setCommand(&setTemp25);
    remoteObj.pressButton();

    SetTemperatureCommand setTemp18(&airConditioner, 18);
    remoteObj.setCommand(&setTemp18);
    remoteObj.pressButton();

    TurnOffCommand turnOff(&airConditioner);
    remoteObj.setCommand(&turnOff);
    remoteObj.pressButton();

    // Undo Command
    remoteObj.undo(); // Undo: Turn Off command => AC is now on
    remoteObj.undo(); // Undo: Set Temperature Command. AC temperature is now 25°C
    remoteObj.undo(); // Undo: Set Temperature Command. AC temperature is now 0°C
    remoteObj.undo(); // Undo: Turn On command => AC is now off

    return 0;
}
