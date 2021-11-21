#include "BudgetApp.h"

BudgetApp::BudgetApp(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses)
    : userManager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses) {

}

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
        budgetManager = new BudgetManager(userManager.getLoggedInUserId(), NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES);
    }
}
