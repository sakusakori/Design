#include <iostream>
#include "Character.h"
using namespace std;

int main() {
    cout << "Word Processor: Issue Demo" << endl;
    // Data: "Hello World"
    // Total 11 characters
    // h = 1 time
    // e = 1 time
    // l = 3 times
    // o = 2 times
    // w = 1 time
    // r = 1 time
    // d = 1 time
    // ' ' = 1 time

    // Create 11 character objects
    Character object1('H', "Arial", 10, 0, 0);
    Character object2('e', "Arial", 10, 0, 1);
    Character object3('l', "Arial", 10, 0, 2);
    Character object4('l', "Arial", 10, 0, 3);
    Character object5('o', "Arial", 10, 0, 4);
    Character object6(' ', "Arial", 10, 0, 5);
    Character object7('W', "Arial", 10, 0, 6);
    Character object8('o', "Arial", 10, 0, 7);
    Character object9('r', "Arial", 10, 0, 8);
    Character object10('l', "Arial", 10, 0, 9);
    Character object11('d', "Arial", 10, 0, 10);

    return 0;
}
