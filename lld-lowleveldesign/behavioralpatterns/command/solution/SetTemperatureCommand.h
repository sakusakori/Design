#pragma once
#include <iostream>
#include "ICommand.h"
#include "AirConditioner.h"
using namespace std;

// Concrete Command
class SetTemperatureCommand : public ICommand {
private:
    AirConditioner* ac;
    int newTemperature;
    int previousTemperature;

public:
    SetTemperatureCommand(AirConditioner* ac, int temperature)
        : ac(ac), newTemperature(temperature), previousTemperature(0) {}

    void execute() override {
        previousTemperature = ac->getTemperature();
        ac->setTemperature(newTemperature);
    }

    void undo() override {
        cout << "Undo: Set Temperature Command. ";
        ac->setTemperature(previousTemperature);
    }
};
