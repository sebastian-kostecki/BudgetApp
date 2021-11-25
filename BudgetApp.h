#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "UserBudget.h"

using namespace std;

class BudgetApp {
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;
    UserManager userManager;
    UserBudget *userBudget;

public:
    BudgetApp(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses);
    ~BudgetApp();
    void registerUser();
    void changeUserPassword();
    void loginUser();
    void logoutUser();
    void addIncome();
    void addExpense();
    void displayBalanceCurrentMonth();
    void displayBalancePreviousMonth();
    void displayBalanceChosenPeriod();
    bool isUserLogin();
    char selectOptionFromMainMenu();
    char selectOptionFormUserMenu();
    void displayStatementWhenUserMakeWrongChoice();
};

#endif // BUDGETAPP_H
