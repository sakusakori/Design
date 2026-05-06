#pragma once
#include <string>
#include <vector>
#include "Group.h"
#include "../User/User.h"
using namespace std;

class GroupController {
public:
    vector<Group*> groupList;

    //create group
    void createNewGroup(string groupId, string groupName, User* createdByUser) {

        //create a new group
        Group* group = new Group();
        group->setGroupId(groupId);
        group->setGroupName(groupName);

        //add the user into the group, as it is created by the USER
        group->addMember(createdByUser);

        //add the group in the list of overall groups
        groupList.push_back(group);
    }

    Group* getGroup(string groupId) {
        for (Group* group : groupList) {
            if (group->getGroupId() == groupId) {
                return group;
            }
        }
        return nullptr;
    }
};
