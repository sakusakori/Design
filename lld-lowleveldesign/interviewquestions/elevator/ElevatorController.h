#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <algorithm>
#include "ElevatorCar.h"
using namespace std;

class ElevatorController {
public:
    // Min heap for going up
    priority_queue<int, vector<int>, greater<int>> upMinPQ;
    // Max heap for going down
    priority_queue<int> downMaxPQ;

    ElevatorCar* elevatorCar;

    mutex mtx;
    condition_variable cv;

    ElevatorController(ElevatorCar* elevatorCar) : elevatorCar(elevatorCar) {}

    void submitRequest(int destinationFloor) {
        enqueueRequest(destinationFloor);
    }

    int getUpQueueSize() {
        lock_guard<mutex> guard(mtx);
        return upMinPQ.size();
    }

    int getDownQueueSize() {
        lock_guard<mutex> guard(mtx);
        return downMaxPQ.size();
    }

private:
    void enqueueRequest(int destinationFloor) {
        cout << "Request details-> destinationFloor: " << destinationFloor
             << " accepted by elevator:" << elevatorCar->id << endl;

        if (destinationFloor == elevatorCar->nextFloorStoppage) {
            return;
        }

        {
            lock_guard<mutex> guard(mtx);
            if (destinationFloor >= elevatorCar->nextFloorStoppage) {
                // Check if not already in queue (linear scan since priority_queue has no contains)
                upMinPQ.push(destinationFloor);
            } else {
                downMaxPQ.push(destinationFloor);
            }
        }

        cv.notify_one(); // wake elevator thread
    }

public:
    void run() {
        controlElevator();
    }

    void controlElevator() {

        while (true) {

            // no request, go to sleep
            {
                unique_lock<mutex> lock(mtx);
                while (upMinPQ.empty() && downMaxPQ.empty()) {
                    cout << "elevator:" << elevatorCar->id << " is IDLE" << endl;
                    elevatorCar->movingDirection = IDLE;
                    cv.wait(lock); // sleep until request arrives
                }
            }

            while (true) {
                int floor;
                {
                    lock_guard<mutex> guard(mtx);
                    if (upMinPQ.empty()) break;
                    floor = upMinPQ.top();
                    upMinPQ.pop();
                }
                cout << "Serving floor: " << floor << " by elevator:" << elevatorCar->id
                     << " currentFloor: " << elevatorCar->currentFloor << endl;
                elevatorCar->moveElevator(floor);
            }

            while (true) {
                int floor;
                {
                    lock_guard<mutex> guard(mtx);
                    if (downMaxPQ.empty()) break;
                    floor = downMaxPQ.top();
                    downMaxPQ.pop();
                }
                cout << "Serving floor: " << floor << " by elevator:" << elevatorCar->id
                     << " currentFloor: " << elevatorCar->currentFloor << endl;
                elevatorCar->moveElevator(floor);
            }
        }
    }
};
