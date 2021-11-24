#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithExpenses.h"
#include "BudgetItem.h"

using namespace std;

class Expenses :public BudgetItem
{
    FileWithExpenses fileWithExpenses;

public:
    Expenses(string nameFileWithExpenses);
};

#endif // EXPENSES_H
