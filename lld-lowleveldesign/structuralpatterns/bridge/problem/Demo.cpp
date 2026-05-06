#include <iostream>
#include "Dog.h"
#include "Fish.h"
#include "Whale.h"
#include "Tree.h"
using namespace std;

// Client
int main() {
    cout << "======= Bridge Design Pattern - Problem Demo ======" << endl;

    Dog_Problem dog;
    dog.breathe();

    Fish_Problem fish;
    fish.breathe();

    Whale_Problem whale;
    whale.breathe();

    Tree_Problem tree;
    tree.breathe();

    return 0;
}
