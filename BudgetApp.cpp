#include "BudgetApp.h"

BudgetApp::BudgetApp(string nameFileWithUsers) : userManager(nameFileWithUsers) {}

void BudgetApp::registerUser() {
    userManager.registerUser();
}

void BudgetApp::showUsers()
{
    userManager.showUsers();
}
