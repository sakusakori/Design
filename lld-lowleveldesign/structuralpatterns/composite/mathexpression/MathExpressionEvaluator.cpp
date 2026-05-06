#include <iostream>
#include "Number.h"
#include "Expression.h"
#include "OperationType.h"
using namespace std;

// Client Code with Composite Pattern
int main() {
    cout << "======= Composite Design Pattern ======" << endl;

    // 2*(1+7) tree structure for evaluation
    /*
                     *
                   /   \
                 2      +
                       / \
                      1   7
    */
    Number two(2);
    Number one(1);
    Number seven(7);

    Expression addExpression(&one, &seven, ADD);
    Expression parentExpression(&two, &addExpression, MULTIPLY);

    cout << parentExpression.evaluate() << endl;

    return 0;
}
