#pragma once
#include <iostream>
using namespace std;

class AirConditioner_Problem {
public:
    bool isOn;
    int temperature;

    AirConditioner_Problem() : isOn(false), temperature(0) {}

    void turnOn() {
        isOn = true;
        cout << "Air conditioner is on" << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "Air conditioner is off" << endl;
    }

    void setTemperature(int temperature) {
        this->temperature = temperature;
        cout << "Air conditioner temperature set to " << temperature << endl;
    }
};
