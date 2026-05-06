#pragma once
#include <string>
using namespace std;

enum PaymentMode {
    CASH,
    ONLINE,
    UPI
};

inline string paymentModeName(PaymentMode mode) {
    switch (mode) {
        case CASH: return "CASH";
        case ONLINE: return "ONLINE";
        case UPI: return "UPI";
        default: return "?";
    }
}
