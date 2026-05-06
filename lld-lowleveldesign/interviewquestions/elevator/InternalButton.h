#pragma once
#include "ElevatorController.h"
#include "InternalDispatcher.h"

class InternalButton {
private:
    ElevatorController* controller;

public:
    InternalButton(ElevatorController* controller)
        : controller(controller) {}

    void pressButton(int destinationFloor) {
        //we can also remove the Internal dispatcher from mid, but generally say for validation, controller and
        //similar code flow like external button, its good to have

        InternalDispatcher::getInstance()
                .submitInternalRequest(destinationFloor, controller);
    }
};
