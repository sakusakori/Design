#pragma once
#include <string>
using namespace std;

enum ItemType {
    COKE,
    PEPSI,
    JUICE,
    SODA
};

inline string itemTypeName(ItemType type) {
    switch (type) {
        case COKE: return "COKE";
        case PEPSI: return "PEPSI";
        case JUICE: return "JUICE";
        case SODA: return "SODA";
        default: return "?";
    }
}
