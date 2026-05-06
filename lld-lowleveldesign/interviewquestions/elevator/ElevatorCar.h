#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "enums/ElevatorDirection.h"
#include "Door.h"
using namespace std;

class ElevatorCar {
public:
    int id;
    int currentFloor;
    int nextFloorStoppage;
    ElevatorDirection movingDirection;
    Door door;

    ElevatorCar(int id) : id(id) {
        currentFloor = 0;
        nextFloorStoppage = 0;
        movingDirection = IDLE;
    }

    void showDisplay() {
        cout << "elevator:" << id << " Current floor: " << currentFloor << " going: " << movingDirection << endl;
    }

    void moveElevator(int destinationFloor) {
        //this is dump object, so if command has come, to go particular direction and particular floor, it just move
        //no matter what its current state and floor.

        this->nextFloorStoppage = destinationFloor;
        if (this->currentFloor == nextFloorStoppage) {
            door.openDoor(id);
            return;
        }

        int startFloor = this->currentFloor;
        door.closeDoor(id);
        if (nextFloorStoppage >= currentFloor) {
            movingDirection = UP;
            showDisplay();
            //+1 i am doing bcoz, floor start from 0,1,2.... so if anyone goes from 1st floor to 2nd, so only 1 floor
            //lift has to move, not 2.
            for (int i = startFloor + 1; i <= nextFloorStoppage; i++) {
                this_thread::sleep_for(chrono::milliseconds(5));
                setCurrentFloor(i);
                showDisplay();
            }
        } else {
            movingDirection = DOWN;
            showDisplay();
            for (int i = startFloor - 1; i >= nextFloorStoppage; i--) {
                this_thread::sleep_for(chrono::milliseconds(5));
                setCurrentFloor(i);
                showDisplay();
            }
        }
        door.openDoor(id);
    }

    void setCurrentFloor(int currentFloor) {
        this->currentFloor = currentFloor;
    }
};
