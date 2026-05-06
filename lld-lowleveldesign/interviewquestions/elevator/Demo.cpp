#include <iostream>
#include <thread>
#include <chrono>
#include "ElevatorCar.h"
#include "ElevatorController.h"
#include "InternalButton.h"
#include "ElevatorScheduler.h"
#include "NearestElevatorStrategy.h"
#include "ExternalDispatcher.h"
#include "Building.h"
using namespace std;

int main() {

    // 1. Create elevator cars and their controllers
    ElevatorCar car1(1);
    ElevatorController controller1(&car1);

    ElevatorCar car2(2);
    ElevatorController controller2(&car2);

    // 2. Create one internal button for each elevator
    InternalButton internalButton_for_elevator1(&controller1);
    InternalButton internalButton_for_elevator2(&controller2);

    // 3. Create Scheduler with Nearest Strategy
    NearestElevatorStrategy nearestStrategy;
    ElevatorScheduler elevatorScheduler(
            {&controller1, &controller2},
            &nearestStrategy
    );

    // 4. Create External Dispatcher
    ExternalDispatcher externalDispatcher(&elevatorScheduler);

    // Create a 5 floor building
    Building building(5, &externalDispatcher);

    // 6. Start both the elevator controllers threads
    thread t1([&controller1]() { controller1.run(); });
    thread t2([&controller2]() { controller2.run(); });

    // Lets submit the requests
    /*
        1. External Call : Floor 3 UP
        2. External Call : Floor 5 DOWN
        3. Internal Call : Elevator 1 (press 4)
        4. Internal Call : Elevator 1 (press 5)
        5. External Call : Floor 1 DOWN
        6. External Call : Floor 2 UP
    */

    building.getFloor(3)->pressUpButton();
    this_thread::sleep_for(chrono::milliseconds(5));

    building.getFloor(5)->pressDownButton();
    this_thread::sleep_for(chrono::milliseconds(5));

    internalButton_for_elevator1.pressButton(4); // user inside elevator 1 presses floor 4
    this_thread::sleep_for(chrono::milliseconds(5));

    internalButton_for_elevator1.pressButton(5); // user inside elevator 1 presses floor 5
    this_thread::sleep_for(chrono::milliseconds(5));

    building.getFloor(1)->pressDownButton();
    this_thread::sleep_for(chrono::milliseconds(5));

    building.getFloor(2)->pressUpButton();
    this_thread::sleep_for(chrono::milliseconds(5));

    internalButton_for_elevator1.pressButton(2); // user inside elevator1 presses floor 2

    // Let elevators finish processing before exiting
    this_thread::sleep_for(chrono::seconds(2));

    // Note: In production, you'd have a graceful shutdown mechanism.
    // The elevator threads run infinite loops, so we detach them here.
    t1.detach();
    t2.detach();

    return 0;
}
