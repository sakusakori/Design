#pragma once
#include <iostream>
#include "WeatherObserver.h"
#include "../observable/WeatherObservable.h"
using namespace std;

// Concrete Observer 2 - Forecast Display - Predicts weather based on pressure changes
class ForecastDisplay : public WeatherObserver {
private:
    WeatherObservable* weatherStation;

public:
    ForecastDisplay(WeatherObservable* weatherStation)
        : weatherStation(weatherStation) {
        weatherStation->addObserver(this);
    }

    // ForecastDisplay implements the update method in its own way
    void update() override {
        cout << "Updating weather data to do some analytics: " << weatherStation->toString() << endl;
        display();
    }

    // Display the forecast based on the current pressure
    void display() {
        cout << "Forecast Details: Displaying information about Rain, "
                  << "Temperature Trends, Significant Weather Events and other phenomemnon..." << endl;
    }
};
