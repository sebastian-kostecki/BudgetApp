#include "UserManager.h"

UserManager::UserManager(string nameFileWithUsers) : fileWithUsers(nameFileWithUsers) {
    users = fileWithUsers.loadUsersFromFile();
    loggedInUserId = 0;
}

void UserManager::registerUser() {
    User user = giveDataOfNewUser();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::giveDataOfNewUser() {
    User user;
    user.setUserId(getNewUserId());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());

    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while(isLoginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isLoginExists(string login) {
    for (vector<User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> getLogin() ==  login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showUsers() {
    for (vector<User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        cout << itr -> getUserId() << endl;
        cout << itr -> getName() << endl;
        cout << itr -> getSurname() << endl;
        cout << itr -> getLogin() << endl;
        cout << itr -> getPassword() << endl;
    }
}

void UserManager::changeUserPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector<User>::iterator itr = users.begin(); itr != users.end(); ++itr) {
        if (itr -> getUserId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.writeChangedUserPasswordToFile(loggedInUserId, newPassword);
}

void UserManager::loginUser()
{
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector<User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            loggedInUserId = 0;
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    loggedInUserId = 0;
}
