#pragma once

// Observer interface - defines the update method
// Concrete observers implement this interface to update their state
// and respond to changes in its OWN way
class WeatherObserver {
public:
    virtual ~WeatherObserver() = default;

    virtual void update() = 0;
};
