#pragma once
#include <climits>
#include "ElevatorSelectionStrategy.h"
#include "ElevatorController.h"
using namespace std;

class LeastBusyStrategy : public ElevatorSelectionStrategy {
public:
    ElevatorController* selectElevator(vector<ElevatorController*>& controllers,
                                       int requestFloor,
                                       ElevatorDirection direction) override {

        ElevatorController* best = nullptr;
        int minLoad = INT_MAX;

        for (ElevatorController* controller : controllers) {
            int load = controller->getUpQueueSize() +
                       controller->getDownQueueSize();

            if (load < minLoad) {
                minLoad = load;
                best = controller;
            }
        }
        return best;
    }
};
