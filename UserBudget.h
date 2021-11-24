#ifndef USERBUDGET_H
#define USERBUDGET_H

#include <iostream>

#include "Incomes.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserBudget
{
    const int LOGGED_IN_USER_ID;
    Incomes incomes;
    Expenses Expenses;

};

#endif // USERBUDGET_H
