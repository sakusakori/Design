#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Step 1: Product class - The complex Student object being built
class Student_Problem {
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

    // Without Builder - Constructor overloading
    // Telescoping Constructor Problem - adding mandatory parameters
    Student_Problem(int rollNumber, int age, string name, string branch)
        : rollNumber(rollNumber), age(age), name(move(name)), branch(move(branch)) {}

    // Telescoping Constructor Problem - adding new parameter - fatherName(optional)
    Student_Problem(int rollNumber, int age, string name, string branch, string fatherName)
        : rollNumber(rollNumber), age(age), name(move(name)), branch(move(branch)),
          fatherName(move(fatherName)) {}

    // Telescoping Constructor Problem - adding new parameter - motherName(optional)
    Student_Problem(int rollNumber, int age, string name, string branch, string fatherName, string motherName)
        : rollNumber(rollNumber), age(age), name(move(name)), branch(move(branch)),
          fatherName(move(fatherName)), motherName(move(motherName)) {}

    // Telescoping Constructor Problem - All arguments constructor
    // Big Constructor with long parameter list
    Student_Problem(int rollNumber, int age, string name, string branch, string fatherName,
                    string motherName, vector<string> subjects, string mobileNo, string emailId)
        : rollNumber(rollNumber), age(age), name(move(name)), branch(move(branch)),
          fatherName(move(fatherName)), motherName(move(motherName)),
          subjects(move(subjects)), mobileNo(move(mobileNo)), emailId(move(emailId)) {}

    void printDetails() {
        cout << "=== Student Details ===" << endl;
        cout << "Id: " << rollNumber
             << ", Name: " << name
             << ", Age: " << age
             << ", Branch: " << branch
             << ", Roll No: " << rollNumber
             << ", Father Name: " << fatherName
             << ", Mother Name: " << motherName
             << ", Subjects: ";
        for (int i = 0; i < (int)subjects.size(); i++) {
            cout << subjects[i];
            if (i < (int)subjects.size() - 1) cout << ",";
        }
        cout << ", Mobile No: " << mobileNo
             << ", Email Id: " << emailId << endl;
    }
};
