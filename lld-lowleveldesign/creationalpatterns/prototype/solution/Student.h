#pragma once
#include <iostream>
#include <string>
#include "StudentPrototype.h"
using namespace std;

// Concrete prototype class
class Student : public StudentPrototype {
public:
    int id;
    string name;
    string branch;
    bool inHighSchool;
private:
    int rollNo;

public:
    Student() : id(0), inHighSchool(false), rollNo(0) {}

    // Clone constructor for efficient copying
    Student(int id, string name, string branch, int rollNo)
        : id(id), name(move(name)), branch(move(branch)),
          inHighSchool(false), rollNo(rollNo) {}

    // setter method
    void setInHighSchool(bool inHighSchool) {
        this->inHighSchool = inHighSchool;
    }

    StudentPrototype* clone() override {
        return new Student(id, name, branch, rollNo);
    }

    void printDetails() {
        cout << "=== Student Details ===" << endl;
        cout << this << ": ";
        cout << "Id: " << id << ", Name: " << name << ", Branch: " << branch
             << ", Roll No: " << rollNo << ", In High School: "
             << (inHighSchool ? "true" : "false") << endl;
    }
};
