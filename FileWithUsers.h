#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string LABEL_OF_USERS;
    const string LABEL_OF_USER;
    const string LABEL_OF_NAME;
    const string LABEL_OF_SURNAME;
    const string LABEL_OF_USER_ID;
    const string LABEL_OF_LOGIN;
    const string LABEL_OF_PASSWORD;
    const string NAME_FILE_WITH_USERS;

public:
    FileWithUsers(string nameFileWithUsers);
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
};

#endif // FILEWITHUSERS_H
