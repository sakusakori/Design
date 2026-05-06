#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "EmployeeDao.h"
#include "EmployeeDaoImpl.h"
using namespace std;

// Proxy class - controls access to RealEmployee
class EmployeeDaoProxy : public EmployeeDao {
private:
    EmployeeDaoImpl empDaoObj;
    string clientRole;

public:
    EmployeeDaoProxy(string clientRole) : clientRole(move(clientRole)) {}

    void getEmployeeInfo(int empID) override {
        if (clientRole == "ADMIN" || clientRole == "USER") {
            empDaoObj.getEmployeeInfo(empID);
        } else {
            throw runtime_error("Access Denied");
        }
    }

    void createEmployee(EmployeeDo obj) override {
        if (clientRole == "ADMIN") {
            empDaoObj.createEmployee(obj);
        } else {
            throw runtime_error("Access Denied");
        }
    }
};
