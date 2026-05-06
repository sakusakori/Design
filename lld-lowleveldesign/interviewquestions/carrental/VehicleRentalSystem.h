#pragma once
#include <vector>
#include <algorithm>
#include "Store.h"
#include "User.h"
using namespace std;

/*
we can also create, StoreManager class which takes
Care of managing List of Stores, and this VehicleRentalSystem has StoreManager

similarly we can also create UserManager, which takes
care of managing list of Users, and this VehicleRentalSystem has UserManager

for now for simplicity i am putting list of stores and list of Users in VehicleRentalSystem class.
 */
class VehicleRentalSystem {
public:
    vector<Store*> storeList;
    vector<User*> userList;

    Store* getStore(int storeId) {
        for (Store* store : storeList) {
            if (store->getStoreId() == storeId) {
                return store;
            }
        }
        return nullptr;
    }

    User* getUser(int index) {
        return userList[index];
    }

    void addStore(Store* store) {
        storeList.push_back(store);
    }

    void addUser(User* user) {
        userList.push_back(user);
    }
};
