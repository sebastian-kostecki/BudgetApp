#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetApp {
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;
    UserManager userManager;
    BudgetManager *budgetManager;

public:
    BudgetApp(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses);
    void registerUser();
    void changeUserPassword();
    void loginUser();



    void showUsers();
};

#endif // BUDGETAPP_H
