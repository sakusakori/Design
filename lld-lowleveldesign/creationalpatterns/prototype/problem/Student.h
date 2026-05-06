#pragma once
#include <iostream>
#include <string>
using namespace std;

// Concrete Class - Whose clone is to be created
class Student_Problem {
public:
    int id;
    string name;
    string branch;
private:
    int rollNo;

public:
    Student_Problem() : id(0), rollNo(0) {}

    Student_Problem(int id, string name, string branch, int rollNo)
        : id(id), name(move(name)), branch(move(branch)), rollNo(rollNo) {}

    void printDetails() {
        cout << "=== Student Details ===" << endl;
        cout << this << ": ";
        cout << "Id: " << id << ", Name: " << name << ", Branch: " << branch << ", Roll No: " << rollNo << endl;
    }
};
