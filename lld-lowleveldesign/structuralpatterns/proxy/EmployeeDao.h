#pragma once
#include "EmployeeDo.h"

// Subject interface - common interface for RealSubject and Proxy
class EmployeeDao {
public:
    virtual ~EmployeeDao() = default;

    virtual void getEmployeeInfo(int empID) = 0;
    virtual void createEmployee(EmployeeDo obj) = 0;
};
