#pragma once
#include <iostream>
#include "ICommand.h"
#include "AirConditioner.h"
using namespace std;

// Concrete Command
class TurnOffCommand : public ICommand {
private:
    AirConditioner* ac;
    bool previousState;

public:
    TurnOffCommand(AirConditioner* ac) : ac(ac), previousState(false) {}

    void execute() override {
        previousState = ac->getIsOn();
        ac->turnOff();
    }

    void undo() override {
        cout << "Undo: Turn Off command. ";
        if (previousState) {
            ac->turnOn();
        }
    }
};
