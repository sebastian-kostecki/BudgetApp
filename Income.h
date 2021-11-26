#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithIncomes.h"
#include "BudgetItem.h"
#include "Item.h"

using namespace std;

class Income :public BudgetItem
{
    FileWithIncomes fileWithIncomes;

public:
    Income(string nameFileWithIncomes, int loggedInUserId);
    void addIncome(int loggedInUserId);
};

#endif // INCOME_H
