#pragma once
#include <string>
using namespace std;

class Location {
public:
    int buildingNo;
    string area;
    string city;
    string state;
    string country;
    int pincode;

    Location(int buildingNo, string area, string city, string state, string country, int pincode)
        : buildingNo(buildingNo), area(move(area)), city(move(city)),
          state(move(state)), country(move(country)), pincode(pincode) {}
};
