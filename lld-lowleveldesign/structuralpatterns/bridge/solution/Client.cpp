#include <iostream>
#include "LungBreathing.h"
#include "GillBreathing.h"
#include "Photosynthesis.h"
#include "Dog.h"
#include "Fish.h"
#include "Tree.h"
using namespace std;

// Client Usage
int main() {
    cout << "======= Bridge Design Pattern - Solution Demo ======" << endl;

    LungBreathing lungBreathing;
    GillBreathing gillBreathing;
    Photosynthesis photosynthesis;

    Dog dog(&lungBreathing);
    Fish fish(&gillBreathing);
    Tree tree(&photosynthesis);

    dog.breathe();
    fish.breathe();
    tree.breathe();

    return 0;
}
