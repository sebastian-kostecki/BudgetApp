#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userId;
    string name;
    string surname;
    string login;
    string password;

public:
    int getUserId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
    void setUserId(int userId);
    void setName(string name);
    void setSurname(string surname);
    void setLogin(string login);
    void setPassword(string password);
};

#endif // USER_H
