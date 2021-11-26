#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithExpenses.h"
#include "BudgetItem.h"

using namespace std;

class Expense :public BudgetItem
{
    FileWithExpenses fileWithExpenses;

public:
    Expense(string nameFileWithExpenses, int loggedInUserId);
    void addExpense(int loggedInUserId);
};

#endif // EXPENSE_H
