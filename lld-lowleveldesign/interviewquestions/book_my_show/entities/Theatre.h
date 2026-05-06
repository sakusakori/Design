#pragma once
#include <string>
#include <vector>
#include "../enums/City.h"
#include "Screen.h"
using namespace std;

class Theatre {
private:
    string name;
    City city;
    vector<Screen*> screens;
    //address info etc.

public:
    Theatre(string name, City city, vector<Screen*> screens)
        : name(move(name)), city(city), screens(move(screens)) {}

    City getCity() { return city; }
    string getName() { return name; }
    vector<Screen*>& getScreens() { return screens; }
};
