#pragma once

#include <iostream>
#include <string>

using namespace std;

class Marker {
public:
    string name;
    string color;
    int price;
    int year;

    Marker(string name, string color, int price, int year)
        : name(name), color(color), price(price), year(year) {}
};
