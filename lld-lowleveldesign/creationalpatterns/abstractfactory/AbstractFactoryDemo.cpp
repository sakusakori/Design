#include <iostream>
#include "CarFactoryProvider.h"
using namespace std;

// Step 7: Client Application
int main() {
    cout << "=====Abstract Factory Design Pattern=====" << endl;

    // Get Factory Provider
    CarFactoryProvider carFactoryProvider;

    // Get Economy Car Factory
    CarFactory* economyCar = carFactoryProvider.getFactory(ECONOMY, "Honda");
    economyCar->produceCompleteVehicle();

    // Get Luxury Car Factory
    CarFactory* luxuryCar = carFactoryProvider.getFactory(LUXURY, "Mercedes");
    luxuryCar->produceCompleteVehicle();

    // Get Premium Car Factory
    CarFactory* premiumCar = carFactoryProvider.getFactory(PREMIUM, "Rolls Royce");
    premiumCar->produceCompleteVehicle();

    delete economyCar;
    delete luxuryCar;
    delete premiumCar;
    return 0;
}
