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
    FileWithUsers fileWithUser;

    User giveDataOfNewUser();
    int getNewUserId();
    bool isLoginExists(string login);

public:
    void registerUser();
};

#endif // USERMANAGER_H
