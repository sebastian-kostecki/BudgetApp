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
    int getLoggedInUserId();
    void registerUser();
    void changeUserPassword();
    void loginUser();
    bool isUserLoggedIn();


    void showUsers();
    void setLoggedUserId(int id)
    {
        loggedInUserId = id;
    }
};

#endif // USERMANAGER_H
