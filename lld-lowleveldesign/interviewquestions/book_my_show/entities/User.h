#pragma once
#include <string>
using namespace std;

class User {
private:
    string userId;
    string name;

public:
    User(string userId, string name)
        : userId(move(userId)), name(move(name)) {}

    string getUserId() { return userId; }
    string getName() { return name; }
};
