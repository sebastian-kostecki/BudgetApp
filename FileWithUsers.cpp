#include "FileWithUsers.h"

FileWithUsers::FileWithUsers(string nameFileWithUsers) : LABEL_OF_USERS("Users"), LABEL_OF_USER("User"), LABEL_OF_USER_ID("userId"), LABEL_OF_NAME("Name"), LABEL_OF_SURNAME("Surname"),
    LABEL_OF_LOGIN("Login"), LABEL_OF_PASSWORD("Password"), NAME_FILE_WITH_USERS(nameFileWithUsers) {}

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    if (xml.Load(NAME_FILE_WITH_USERS)) {
        xml.FindElem(LABEL_OF_USERS);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER_ID, user.getUserId());
        xml.AddElem(LABEL_OF_NAME, user.getName());
        xml.AddElem(LABEL_OF_SURNAME, user.getSurname());
        xml.AddElem(LABEL_OF_LOGIN, user.getLogin());
        xml.AddElem(LABEL_OF_PASSWORD, user.getPassword());
        xml.Save(NAME_FILE_WITH_USERS);
    } else {
        xml.AddElem(LABEL_OF_USERS);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER_ID, user.getUserId());
        xml.AddElem(LABEL_OF_NAME, user.getName());
        xml.AddElem(LABEL_OF_SURNAME, user.getSurname());
        xml.AddElem(LABEL_OF_LOGIN, user.getLogin());
        xml.AddElem(LABEL_OF_PASSWORD, user.getPassword());
        xml.Save(NAME_FILE_WITH_USERS);
    }
}

vector<User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector<User> users;
    CMarkup xml;

    if (xml.Load(NAME_FILE_WITH_USERS)) {
        xml.FindElem(LABEL_OF_USERS);
        xml.IntoElem();
        while (xml.FindElem(LABEL_OF_USER)) {
            xml.IntoElem();
            xml.FindElem();
            user.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem();
            user.setName(xml.GetData());
            xml.FindElem();
            user.setSurname(xml.GetData());
            xml.FindElem();
            user.setLogin(xml.GetData());
            xml.FindElem();
            user.setPassword(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}

void FileWithUsers::writeChangedUserPasswordToFile(int userId, string newPassword) {
    CMarkup xml;
    if (xml.Load(NAME_FILE_WITH_USERS)) {
        xml.FindElem(LABEL_OF_USERS);
        xml.IntoElem();
        while (xml.FindElem(LABEL_OF_USER)) {
            xml.IntoElem();
            xml.FindElem(LABEL_OF_USER_ID);
            if (AuxiliaryMethods::convertStringToInteger(xml.GetData()) == userId) {
                xml.FindElem(LABEL_OF_PASSWORD);
                xml.SetData(newPassword);
            }
            xml.OutOfElem();
        }
        xml.Save(NAME_FILE_WITH_USERS);
    }
}
