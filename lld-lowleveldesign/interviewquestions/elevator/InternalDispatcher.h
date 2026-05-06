#pragma once
#include "ElevatorController.h"

class InternalDispatcher {
private:
    InternalDispatcher() {}

public:
    static InternalDispatcher& getInstance() {
        static InternalDispatcher instance;
        return instance;
    }

    // elevatorController is known based on button press origin
    void submitInternalRequest(int destinationFloor, ElevatorController* controller) {
        controller->submitRequest(destinationFloor);
    }
};
