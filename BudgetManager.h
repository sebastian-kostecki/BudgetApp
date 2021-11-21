#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>

using namespace std;

class BudgetManager
{
    const int LOGGED_IN_USER_ID;

public:
    BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses);

};

#endif // BUDGETMANAGER_H
