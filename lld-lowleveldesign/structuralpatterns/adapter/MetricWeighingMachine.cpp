#include <iostream>
#include "ImperialWeighingMachineImpl.h"
#include "WeightMachineAdapterImpl.h"
using namespace std;

// Client - Metric Weighing Machine
int main() {
    cout << "======= Adapter Design Pattern ======" << endl;

    // ImperialWeighingMachine - Existing weighing machine is used to weigh the baby in pounds
    double weighingScaleReading = 25.0; // say the baby's weight is 25 pounds
    ImperialWeighingMachineImpl imperialWeighingMachine(weighingScaleReading);

    // Adapter to convert to KG
    WeightMachineAdapterImpl weightMachineAdapter(&imperialWeighingMachine);

    // Client gets weight in Kilograms
    cout << "Weight in KG: " << weightMachineAdapter.getWeightInKg() << endl;

    return 0;
}
