#pragma once
#include "ExternalButton.h"
#include "ExternalDispatcher.h"
#include "enums/ElevatorDirection.h"

class Floor {
public:
    int floorNumber;
    ExternalButton upButton;
    ExternalButton downButton;

    Floor(int floorNumber, ExternalDispatcher* dispatcher)
        : floorNumber(floorNumber),
          upButton(dispatcher),
          downButton(dispatcher) {}

    void pressUpButton() {
        upButton.pressButton(floorNumber, UP);
    }

    void pressDownButton() {
        downButton.pressButton(floorNumber, DOWN);
    }
};
