#include <iostream>
#include "EmployeeDaoProxy.h"
using namespace std;

// Client
int main() {
    cout << "===== Proxy Design Pattern =====" << endl;

    EmployeeDaoProxy userProxyObj("USER");
    userProxyObj.getEmployeeInfo(1); // access granted

    try {
        userProxyObj.createEmployee(EmployeeDo()); // access denied
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
