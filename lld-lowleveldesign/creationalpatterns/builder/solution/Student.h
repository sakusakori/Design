#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "StudentBuilder.h"
using namespace std;

// Step 1: Product class - Complex Student object
class Student {
public:
    // mandatory fields
    int rollNumber;
    int age;
    string name;
    string branch;
    // optional fields
    string fatherName;
    string motherName;
    vector<string> subjects;
    string mobileNo;
    string emailId;

    // Constructor - only builder can create
    Student(StudentBuilder* builder) {
        this->rollNumber = builder->rollNumber;
        this->age = builder->age;
        this->name = builder->name;
        this->branch = builder->branch;
        this->fatherName = builder->fatherName;
        this->motherName = builder->motherName;
        this->subjects = builder->subjects;
        this->mobileNo = builder->mobileNo;
        this->emailId = builder->emailId;
    }

    string toString() {
        string result = " roll number: " + to_string(rollNumber) +
                " age: " + to_string(age) +
                " name: " + name +
                " branch: " + branch +
                " father name: " + fatherName +
                " mother name: " + motherName +
                " subjects: " + subjects[0] + "," + subjects[1] + "," + subjects[2] +
                " mobile no: " + mobileNo +
                " email id: " + emailId;
        return result;
    }
};

// Deferred build() definition - needs Student to be complete
inline Student* StudentBuilder::build() {
    return new Student(this);
}
