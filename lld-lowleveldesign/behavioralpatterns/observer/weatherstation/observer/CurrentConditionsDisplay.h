#pragma once
#include <iostream>
#include "WeatherObserver.h"
#include "../observable/WeatherObservable.h"
using namespace std;

// Concrete Observer 1 - Current Conditions Display (on TV or Mobile)
class CurrentConditionsDisplay : public WeatherObserver {
private:
    WeatherObservable* weatherStation;

public:
    CurrentConditionsDisplay(WeatherObservable* weatherStation)
        : weatherStation(weatherStation) {
        weatherStation->addObserver(this);
    }

    // CurrentConditionsDisplay implements the update method in its own way
    void update() override {
        cout << "Saving weather data... " << endl;
        display();
    }

    // Display the current weather conditions
    void display() {
        cout << "Current Weather Conditions: " << weatherStation->toString() << endl;
    }
};
