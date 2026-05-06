#include <iostream>
#include "Student.h"
using namespace std;

// Client
int main() {
    cout << "======= Prototype Design Pattern ======" << endl;

    // Create initial prototypes (expensive operations)
    Student student(5, "Rita", "CSE", 224);
    student.printDetails();

    // Clone objects (fast operations)
    Student* studentClone = (Student*)student.clone();
    studentClone->setInHighSchool(true);
    studentClone->printDetails();

    cout << "Same object? " << (&student == studentClone ? "true" : "false") << endl; // false

    delete studentClone;
    return 0;
}
