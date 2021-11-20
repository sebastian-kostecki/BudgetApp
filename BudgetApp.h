#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class BudgetApp {
    UserManager userManager;

public:
    BudgetApp(string nameFileWithUsers);
    void registerUser();
};

#endif // BUDGETAPP_H
