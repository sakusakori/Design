#pragma once
#include <iostream>
using namespace std;

// Receiver - The AC Device that performs actual operations
class AirConditioner {
public:
    bool isOn;
    int temperature;

    AirConditioner() : isOn(false), temperature(0) {}

    void turnOn() {
        isOn = true;
        cout << "Air conditioner is on" << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "Air conditioner is off" << endl;
    }

    bool getIsOn() { return isOn; }
    void setOn(bool on) { isOn = on; }

    int getTemperature() { return temperature; }

    void setTemperature(int temp) {
        temperature = temp;
        cout << "Air conditioner temperature set to " << temp << "°C" << endl;
    }
};
