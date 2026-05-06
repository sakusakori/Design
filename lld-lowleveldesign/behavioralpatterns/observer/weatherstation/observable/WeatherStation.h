#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "WeatherObservable.h"
#include "../observer/WeatherObserver.h"
using namespace std;

// Concrete Observable (Subject)
// WeatherStation - the concrete observable class that holds weather data
class WeatherStation : public WeatherObservable {
private:
    // List of observers registered for updates
    vector<WeatherObserver*> observers;
    // Observable Data
    float temperature = 0;
    float humidity = 0;
    float pressure = 0;

public:
    WeatherStation() = default;

    void addObserver(WeatherObserver* observer) override {
        observers.push_back(observer);
        cout << "[+] Observer registered: " << typeid(*observer).name() << endl;
    }

    void removeObserver(WeatherObserver* observer) override {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
        cout << "[-] Observer removed: " << typeid(*observer).name() << endl;
    }

    void notifyObservers() override {
        for (WeatherObserver* observer : observers) {
            // Notify each observer about the change in weather data(state)
            observer->update(); // Observer will update its state based on the new data and respond accordingly
        }
    }

    // Method to update weather measurements
    void setWeatherReadings(float temperature, float humidity, float pressure) override {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        notifyObservers();
    }

    // Getters for observers to access weather data
    float getTemperature() { return temperature; }
    float getHumidity() { return humidity; }
    float getPressure() { return pressure; }

    string toString() override {
        return "WeatherStation{temperature=" + to_string(temperature)
             + ", humidity=" + to_string(humidity)
             + ", pressure=" + to_string(pressure) + "}";
    }
};
