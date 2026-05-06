#pragma once
#include <string>
using namespace std;

enum City {
    BANGALORE,
    DELHI
};

inline string cityName(City city) {
    switch (city) {
        case BANGALORE: return "BANGALORE";
        case DELHI: return "DELHI";
        default: return "?";
    }
}
