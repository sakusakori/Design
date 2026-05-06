#include <iostream>
#include "Student.h"
using namespace std;

// Client
int main() {
    Student_Problem studentOrg(1, "Aman", "CSE", 123);
    studentOrg.printDetails();

    // create a clone of the student object
    Student_Problem studentClone;
    studentClone.id = studentOrg.id;
    studentClone.name = studentOrg.name;
    studentClone.branch = studentOrg.branch;
    // studentClone.rollNo = studentOrg.rollNo; // Compilation error - rollNo is private

    return 0;
}
