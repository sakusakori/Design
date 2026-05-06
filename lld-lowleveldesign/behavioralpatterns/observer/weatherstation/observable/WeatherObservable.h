#pragma once
#include <string>
using namespace std;

class WeatherObserver;

// Observable(Subject) interface
// Defines methods for managing observers and notifying them of changes
class WeatherObservable {
public:
    virtual ~WeatherObservable() = default;

    virtual void addObserver(WeatherObserver* observer) = 0;

    virtual void removeObserver(WeatherObserver* observer) = 0;

    virtual void notifyObservers() = 0;

    virtual void setWeatherReadings(float temperature, float humidity, float pressure) = 0;

    virtual string toString() = 0;
};
