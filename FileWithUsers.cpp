#include "FileWithUsers.h"

FileWithUsers::FileWithUsers() : LABEL_OF_USERS("Users"), LABEL_OF_USER("User"), LABEL_OF_USER_ID("userId"), LABEL_OF_NAME("Name"), LABEL_OF_SURNAME("Surname"),
LABEL_OF_LOGIN("Login"), LABEL_OF_PASSWORD("Password") {}

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    if (xml.Load("user.xml"))
    {
        xml.FindElem(LABEL_OF_USERS);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER_ID, user.getUserId());
        xml.AddElem(LABEL_OF_NAME, user.getName());
        xml.AddElem(LABEL_OF_SURNAME, user.getSurname());
        xml.AddElem(LABEL_OF_LOGIN, user.getLogin());
        xml.AddElem(LABEL_OF_PASSWORD, user.getPassword());
        xml.Save("user.xml");
    }
    else
    {
        xml.AddElem(LABEL_OF_USERS);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_USER_ID, user.getUserId());
        xml.AddElem(LABEL_OF_NAME, user.getName());
        xml.AddElem(LABEL_OF_SURNAME, user.getSurname());
        xml.AddElem(LABEL_OF_LOGIN, user.getLogin());
        xml.AddElem(LABEL_OF_PASSWORD, user.getPassword());
        xml.Save("user.xml");
    }
}
