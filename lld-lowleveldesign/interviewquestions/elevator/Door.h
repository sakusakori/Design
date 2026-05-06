#pragma once
#include <iostream>
#include "enums/DoorState.h"
using namespace std;

class Door {
private:
    DoorState doorState;

public:
    Door() {
        doorState = DOOR_CLOSED;
    }

    void openDoor(int id) {
        doorState = DOOR_OPEN;
        cout << "Opening the Elevator door of elevator:" << id << endl;
    }

    void closeDoor(int id) {
        doorState = DOOR_CLOSED;
        cout << "Closing the Elevator door of elevator:" << id << endl;
    }
};
