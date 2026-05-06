#pragma once
#include <vector>
#include "ElevatorController.h"
#include "ElevatorSelectionStrategy.h"
#include "enums/ElevatorDirection.h"
using namespace std;

class ElevatorScheduler {
private:
    vector<ElevatorController*> controllers;
    ElevatorSelectionStrategy* strategy;

public:
    ElevatorScheduler(vector<ElevatorController*> controllers,
                      ElevatorSelectionStrategy* strategy)
        : controllers(move(controllers)), strategy(strategy) {}

    void setStrategy(ElevatorSelectionStrategy* strategy) {
        this->strategy = strategy;
    }

    ElevatorController* assignElevator(int floor, ElevatorDirection direction) {
        return strategy->selectElevator(controllers, floor, direction);
    }
};
