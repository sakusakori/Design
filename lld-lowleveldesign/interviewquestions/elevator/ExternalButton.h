#pragma once
#include "ExternalDispatcher.h"
#include "enums/ElevatorDirection.h"

class ExternalButton {
private:
    ExternalDispatcher* dispatcher;

public:
    ExternalButton(ExternalDispatcher* dispatcher)
        : dispatcher(dispatcher) {}

    // this direction of external button is only helpful in selecting the correct elevator
    void pressButton(int floor, ElevatorDirection direction) {
        dispatcher->submitExternalRequest(floor, direction);
    }
};
