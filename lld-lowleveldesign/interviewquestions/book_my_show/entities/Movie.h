#pragma once
#include <string>
using namespace std;

class Movie {
private:
    string name;
    //duration

public:
    Movie(string name) : name(move(name)) {}

    string getName() { return name; }
};
