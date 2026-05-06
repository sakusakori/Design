#pragma once
#include <string>
using namespace std;

class User {
public:
    int userId;
    string userName;
    string drivingLicenseNo;

    User(int userId, string userName, string drivingLicenseNo)
        : userId(userId), userName(move(userName)),
          drivingLicenseNo(move(drivingLicenseNo)) {}

    int getUserId() { return userId; }
    void setUserId(int id) { userId = id; }

    string getUserName() { return userName; }
    void setUserName(string name) { userName = move(name); }

    string getDrivingLicenseNo() { return drivingLicenseNo; }
    void setDrivingLicenseNo(string license) { drivingLicenseNo = move(license); }
};
