#include "BudgetApp.h"

BudgetApp::BudgetApp(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses)
    : userManager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses) {
    userBudget = nullptr;
}

BudgetApp::~BudgetApp() {
    delete userBudget;
    userBudget = nullptr;
}

void BudgetApp::registerUser() {
    userManager.registerUser();
}

void BudgetApp::changeUserPassword() {
    userManager.changeUserPassword();
}

void BudgetApp::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        userBudget = new UserBudget(userManager.getLoggedInUserId(), NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES);
    }
}

void BudgetApp::logoutUser() {
    userManager.logoutUser();
    delete userBudget;
    userBudget = nullptr;
}

void BudgetApp::addIncome() {
    if (userManager.isUserLoggedIn())
        userBudget->addIncome();
}

void BudgetApp::addExpense() {
    if (userManager.isUserLoggedIn())
        userBudget->addExpense();
}

void BudgetApp::displayBalanceCurrentMonth() {
    userBudget->displayBalanceCurrentMonth();
}

void BudgetApp::displayBalancePreviousMonth() {
    userBudget->displayBalancePreviousMonth();
}

void BudgetApp::displayBalanceChosenPeriod() {
    userBudget->displayBalanceChosenPeriod();
}
