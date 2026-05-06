#include <iostream>
#include "observable/WeatherStation.h"
#include "observer/CurrentConditionsDisplay.h"
#include "observer/ForecastDisplay.h"
using namespace std;

// Client code to demonstrate the Observer Pattern
int main() {
    cout << "###### State Design Pattern ######" << endl;

    // Create the weather station (observable/subject)
    WeatherStation weatherStation;

    // Create displays (observers)
    CurrentConditionsDisplay currentDisplay(&weatherStation);
    ForecastDisplay forecastDisplay(&weatherStation);

    cout << "===>>> Initial Weather Update" << endl;
    weatherStation.setWeatherReadings(80, 65, 30.4f);

    cout << "===>>> Second Weather Update" << endl;
    weatherStation.setWeatherReadings(82, 70, 29.2f);

    // Remove forecast display
    weatherStation.removeObserver(&forecastDisplay);

    cout << "===>>> Third Weather Update" << endl;
    weatherStation.setWeatherReadings(70, 21, 29.2f);
    // Forecast display will not be notified

    return 0;
}
