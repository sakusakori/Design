#pragma once
#include <iostream>
using namespace std;

class Bulb {
public:
    bool isOn;

    Bulb() : isOn(false) {}

    void turnOn() {
        isOn = true;
        cout << "Bulb is on" << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "Bulb is off" << endl;
    }
};
