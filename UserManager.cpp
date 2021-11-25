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

void UserManager::loginUser() {
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

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

void UserManager::logoutUser() {
    loggedInUserId = 0;
}

char UserManager::selectOptionFromMainMenu() {
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadSign();
    return choice;
}

char UserManager::selectOptionFormUserMenu() {
    char choice;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadSign();
    return choice;
}
