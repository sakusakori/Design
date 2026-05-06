#pragma once
#include <cmath>
#include <climits>
#include "ElevatorSelectionStrategy.h"
#include "ElevatorController.h"
using namespace std;

class NearestElevatorStrategy : public ElevatorSelectionStrategy {
public:
    ElevatorController* selectElevator(vector<ElevatorController*>& controllers,
                                       int requestFloor,
                                       ElevatorDirection direction) override {

        ElevatorController* best = nullptr;
        int minDistance = INT_MAX;

        //1. Pick the one which is going in same direction and minimum distance from the destination
        for (ElevatorController* controller : controllers) {
            int nextFloorStoppage = controller->elevatorCar->nextFloorStoppage;

            // Good candidate if moving same direction & not passed requested floor
            bool isSameDirectionCandidate =
                    controller->elevatorCar->movingDirection == direction &&
                    ((direction == UP && nextFloorStoppage <= requestFloor) ||
                     (direction == DOWN && nextFloorStoppage >= requestFloor));

            int dist = abs(nextFloorStoppage - requestFloor);

            if (isSameDirectionCandidate && dist < minDistance) {
                minDistance = dist;
                best = controller;
            }
        }

        // fallback: if not able to choose, pick the idle one
        if (best == nullptr) {
            for (ElevatorController* controller : controllers) {
                if (controller->elevatorCar->movingDirection == IDLE) {
                    best = controller;
                    break;
                }
            }

            //reached here means, no lift is going in same direction and no lift is IDLE too, then pick any lift
            if (best == nullptr) {
                best = controllers[0];
            }
        }
        return best;
    }
};
