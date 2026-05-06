#pragma once
#include <iostream>
#include "EmployeeDao.h"
using namespace std;

// RealSubject - the actual employee object that does the real work
class EmployeeDaoImpl : public EmployeeDao {
public:
    void getEmployeeInfo(int empID) override {
        cout << "Fetching employee info for ID: " << empID << endl;
    }

    void createEmployee(EmployeeDo obj) override {
        cout << "Creating employee" << endl;
    }
};
