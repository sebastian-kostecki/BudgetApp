#include "BudgetApp.h"

BudgetApp::BudgetApp(string nameFileWithUsers) : userManager(nameFileWithUsers) {}

void BudgetApp::registerUser() {
    userManager.registerUser();
}

void BudgetApp::showUsers() {
    userManager.showUsers();
}

void BudgetApp::changeUserPassword() {
    userManager.changeUserPassword();
}

void BudgetApp::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        //create Login Panel For User
    }
}
