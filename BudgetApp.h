#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class BudgetApp {
    UserManager userManager;

public:
    void registerUser();
};

#endif // BUDGETAPP_H
