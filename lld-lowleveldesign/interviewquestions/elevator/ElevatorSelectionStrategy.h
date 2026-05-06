#pragma once
#include <vector>
#include "enums/ElevatorDirection.h"
using namespace std;

class ElevatorController;

class ElevatorSelectionStrategy {
public:
    virtual ~ElevatorSelectionStrategy() = default;

    virtual ElevatorController* selectElevator(vector<ElevatorController*>& controllers,
                                               int requestFloor,
                                               ElevatorDirection direction) = 0;
};
