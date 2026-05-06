#include <iostream>
#include "DBConnectionEager.h"
#include "DBConnectionLazy.h"
#include "DBConnectionThreadSafe.h"
#include "DBConnectionDoubleLocking.h"
using namespace std;

// Test Singleton Implementation
int main() {
    cout << "======= Singleton Design Pattern ======" << endl;

    cout << "====== Testing Eager Initialization ======" << endl;
    DBConnectionEager& eager1 = DBConnectionEager::getInstance();
    DBConnectionEager& eager2 = DBConnectionEager::getInstance();
    eager1.displayMessage();
    eager2.displayMessage();
    cout << "Same instance? " << (&eager1 == &eager2 ? "true" : "false") << endl;

    cout << "====== Testing Lazy Initialization ======" << endl;
    DBConnectionLazy* lazy1 = DBConnectionLazy::getInstance();
    DBConnectionLazy* lazy2 = DBConnectionLazy::getInstance();
    lazy1->displayMessage();
    lazy2->displayMessage();
    cout << "Same instance? " << (lazy1 == lazy2 ? "true" : "false") << endl;

    cout << "====== Testing Thread Safe ======" << endl;
    DBConnectionThreadSafe* threadSafe1 = DBConnectionThreadSafe::getInstance();
    DBConnectionThreadSafe* threadSafe2 = DBConnectionThreadSafe::getInstance();
    threadSafe1->displayMessage();
    threadSafe2->displayMessage();
    cout << "Same instance? " << (threadSafe1 == threadSafe2 ? "true" : "false") << endl;

    cout << "====== Testing Double Locking ======" << endl;
    DBConnectionDoubleLocking* doubleLocking1 = DBConnectionDoubleLocking::getInstance();
    DBConnectionDoubleLocking* doubleLocking2 = DBConnectionDoubleLocking::getInstance();
    doubleLocking1->displayMessage();
    doubleLocking2->displayMessage();
    cout << "Same instance? " << (doubleLocking1 == doubleLocking2 ? "true" : "false") << endl;

    return 0;
}
