#pragma once
#include "StudentBuilder.h"

// Step 4: Concrete Builder for MBA Students
class MBAStudentBuilder : public StudentBuilder {
public:
    // MBA-specific methods
    StudentBuilder* setSubjects() override {
        vector<string> mbaSubjectsList;
        mbaSubjectsList.push_back("Micro Economics");
        mbaSubjectsList.push_back("Business Studies");
        mbaSubjectsList.push_back("Operations Management");
        mbaSubjectsList.push_back("Financial Management");
        this->subjects = mbaSubjectsList;
        return this;
    }
};
