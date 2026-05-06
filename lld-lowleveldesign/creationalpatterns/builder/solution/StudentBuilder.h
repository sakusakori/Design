#pragma once
#include <string>
#include <vector>
using namespace std;

class Student;

// Step 2: Abstract Builder interface
class StudentBuilder {
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

    virtual ~StudentBuilder() = default;

    StudentBuilder* setRollNumber(int rollNumber) {
        this->rollNumber = rollNumber;
        return this;
    }

    StudentBuilder* setAge(int age) {
        this->age = age;
        return this;
    }

    StudentBuilder* setName(string name) {
        this->name = move(name);
        return this;
    }

    StudentBuilder* setBranch(string branch) {
        this->branch = move(branch);
        return this;
    }

    StudentBuilder* setFatherName(string fatherName) {
        this->fatherName = move(fatherName);
        return this;
    }

    StudentBuilder* setMotherName(string motherName) {
        this->motherName = move(motherName);
        return this;
    }

    StudentBuilder* setMobileNo(string mobileNo) {
        this->mobileNo = move(mobileNo);
        return this;
    }

    StudentBuilder* setEmailId(string emailId) {
        this->emailId = move(emailId);
        return this;
    }

    virtual StudentBuilder* setSubjects() = 0;

    // Build method - defined after Student is complete
    Student* build();
};
