#ifndef USERBUDGET_H
#define USERBUDGET_H

#include <iostream>

#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class UserBudget
{
    const int LOGGED_IN_USER_ID;
    Incomes incomes;
    Expenses expenses;

public:
    UserBudget(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses);
    void addIncome();
    void addExpense();
};

#endif // USERBUDGET_H
