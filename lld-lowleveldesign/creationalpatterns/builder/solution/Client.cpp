#include <iostream>
#include "StudentRegistrationDirector.h"
#include "EngineeringStudentBuilder.h"
#include "MBAStudentBuilder.h"
#include "Student.h"
using namespace std;

// Step 6: Client demonstration
int main() {
    cout << "===== Builder Design Pattern =====" << endl;

    // Create director objects
    EngineeringStudentBuilder enggBuilder;
    MBAStudentBuilder mbaBuilder;
    StudentRegistrationDirector enggStudentDirector(&enggBuilder);
    StudentRegistrationDirector mbaStudentDirector(&mbaBuilder);

    // Create students using different builders
    Student* engineerStudent = enggStudentDirector.createStudent();
    Student* mbaStudent = mbaStudentDirector.createStudent();

    // Print student details
    cout << "===> Student details:" << engineerStudent->toString() << endl;
    cout << "===> Student details:" << mbaStudent->toString() << endl;

    delete engineerStudent;
    delete mbaStudent;

    return 0;
}
