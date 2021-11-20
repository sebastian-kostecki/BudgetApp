#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector<User> users;
    FileWithUsers fileWithUsers;

    User giveDataOfNewUser();
    int getNewUserId();
    bool isLoginExists(string login);

public:
    UserManager(string nameFileWithUsers);
    void registerUser();
    void showUsers();
};

#endif // USERMANAGER_H
