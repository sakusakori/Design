#include <iostream>
#include <vector>
#include <map>
#include "Entity/ParkingSpot.h"
#include "Entity/Vehicle.h"
#include "enums/VehicleType.h"
#include "LookupStrategy/RandomLookupStrategy.h"
#include "spotManagers/TwoWheelerSpotManager.h"
#include "spotManagers/FourWheelerSpotManager.h"
#include "parkinglot/ParkingLevel.h"
#include "parkinglot/ParkingBuilding.h"
#include "parkinglot/ParkingLot.h"
#include "payment/CashPayment.h"
#include "payment/UPIPayment.h"
#include "pricing/CostComputation.h"
#include "pricing/FixedPricingStrategy.h"
using namespace std;

int main() {

    RandomLookupStrategy strategy;

    // Level 1 spots
    ParkingSpot l1s1("L1-S1"), l1s2("L1-S2"), l1s3("L1-S3");

    TwoWheelerSpotManager l1TwoWheeler({&l1s1, &l1s2}, &strategy);
    FourWheelerSpotManager l1FourWheeler({&l1s3}, &strategy);

    map<VehicleType, ParkingSpotManager*> levelOneManagers;
    levelOneManagers[TWO_WHEELER] = &l1TwoWheeler;
    levelOneManagers[FOUR_WHEELER] = &l1FourWheeler;

    ParkingLevel level1(1, levelOneManagers);

    // Level 2 spots
    ParkingSpot l2s1("L2-S1"), l2s2("L2-S2"), l2s3("L2-S3");

    TwoWheelerSpotManager l2TwoWheeler({&l2s1}, &strategy);
    FourWheelerSpotManager l2FourWheeler({&l2s2, &l2s3}, &strategy);

    map<VehicleType, ParkingSpotManager*> levelTwoManagers;
    levelTwoManagers[TWO_WHEELER] = &l2TwoWheeler;
    levelTwoManagers[FOUR_WHEELER] = &l2FourWheeler;

    ParkingLevel level2(2, levelTwoManagers);

    // Building
    FixedPricingStrategy pricingStrategy;
    CostComputation costComputation(&pricingStrategy);

    ParkingBuilding parkingBuilding({&level1, &level2}, &costComputation);

    // Gates
    EntranceGate entranceGate;
    CostComputation exitCostComputation(&pricingStrategy);
    ExitGate exitGate(&exitCostComputation);

    // Parking Lot
    ParkingLot parkingLot(&parkingBuilding, &entranceGate, &exitGate);

    // Vehicles
    Vehicle bike("BIKE-101", TWO_WHEELER);
    Vehicle car("CAR-201", FOUR_WHEELER);

    Ticket* t1 = parkingLot.vehicleArrives(&bike);
    Ticket* t2 = parkingLot.vehicleArrives(&car);

    CashPayment cashPayment;
    UPIPayment upiPayment;

    parkingLot.vehicleExits(t1, &cashPayment);
    parkingLot.vehicleExits(t2, &upiPayment);

    delete t1;
    delete t2;

    return 0;
}
