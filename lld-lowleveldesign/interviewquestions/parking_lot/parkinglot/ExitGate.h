#pragma once
#include <iostream>
#include <stdexcept>
#include "../Ticket.h"
#include "../payment/Payment.h"
#include "../pricing/CostComputation.h"
#include "ParkingBuilding.h"
using namespace std;

class ExitGate {
private:
    CostComputation* costComputation;

    double calculatePrice(Ticket* ticket) {
        return costComputation->compute(ticket);
    }

public:
    ExitGate(CostComputation* costComputation)
        : costComputation(costComputation) {}

    void completeExit(ParkingBuilding* building, Ticket* ticket, Payment* payment) {
        double amount = calculatePrice(ticket);

        bool success = payment->pay(amount);
        if (!success) {
            throw runtime_error("Payment failed. Exit denied.");
        }

        building->release(ticket);
        cout << "Exit successful. Gate opened." << endl;
    }
};
