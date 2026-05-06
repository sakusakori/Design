#pragma once
#include "ElevatorScheduler.h"
#include "enums/ElevatorDirection.h"

class ExternalDispatcher {
public:
    ElevatorScheduler* scheduler;

    ExternalDispatcher(ElevatorScheduler* scheduler)
        : scheduler(scheduler) {}

    void submitExternalRequest(int floor, ElevatorDirection direction) {
        ElevatorController* controller =
                scheduler->assignElevator(floor, direction);
        controller->submitRequest(floor);
    }
};
