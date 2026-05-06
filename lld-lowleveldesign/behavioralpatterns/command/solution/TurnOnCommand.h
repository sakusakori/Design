#pragma once
#include <iostream>
#include "ICommand.h"
#include "AirConditioner.h"
using namespace std;

// Concrete Commands
class TurnOnCommand : public ICommand {
private:
    AirConditioner* ac;
    bool previousState;

public:
    TurnOnCommand(AirConditioner* ac) : ac(ac), previousState(false) {}

    void execute() override {
        previousState = ac->getIsOn();
        ac->turnOn();
    }

    void undo() override {
        cout << "Undo: Turn On command. ";
        if (!previousState) {
            ac->turnOff();
        }
    }
};
