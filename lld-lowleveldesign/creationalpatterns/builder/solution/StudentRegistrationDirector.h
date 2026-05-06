#pragma once
#include "Student.h"
#include "StudentBuilder.h"
#include "EngineeringStudentBuilder.h"
#include "MBAStudentBuilder.h"

// Step 5: Director class for common student registration processes
class StudentRegistrationDirector {
public:
    StudentBuilder* studentBuilder;

    StudentRegistrationDirector(StudentBuilder* studentBuilder)
        : studentBuilder(studentBuilder) {}

    Student* createStudent() {
        if (dynamic_cast<EngineeringStudentBuilder*>(studentBuilder) != nullptr) {
            return createEngineeringStudent();
        } else if (dynamic_cast<MBAStudentBuilder*>(studentBuilder) != nullptr) {
            return createMBAStudent();
        }
        return nullptr;
    }

private:
    Student* createEngineeringStudent() {
        return studentBuilder->setRollNumber(1)
                ->setAge(22)
                ->setName("John")
                ->setFatherName("Paul")
                ->setMotherName("Jane")
                ->setBranch("Computer Science and Engineering")
                ->setSubjects()
                ->build();
    }

    Student* createMBAStudent() {
        return studentBuilder->setRollNumber(2)
                ->setAge(24)
                ->setName("Sarah")
                ->setFatherName("Gabriel")
                ->setMotherName("Taylor")
                ->setBranch("Business Administration")
                ->setSubjects()
                ->setMobileNo("9876543210")
                ->setEmailId("sarahgabriel@iitb.com")
                ->build();
    }
};
