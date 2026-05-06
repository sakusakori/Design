#pragma once
#include "StudentBuilder.h"

// Step 3: Concrete Builder for Engineering Students
class EngineeringStudentBuilder : public StudentBuilder {
public:
    // Engineering-specific methods
    StudentBuilder* setSubjects() override {
        vector<string> enggSubjectsList;
        enggSubjectsList.push_back("Operating Systems");
        enggSubjectsList.push_back("Computer Architecture");
        enggSubjectsList.push_back("Data Structures");
        enggSubjectsList.push_back("DBMS");
        this->subjects = enggSubjectsList;
        return this;
    }
};
