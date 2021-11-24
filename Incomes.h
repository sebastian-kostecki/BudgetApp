#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithIncomes.h"
#include "BudgetItem.h"
#include "Item.h"

using namespace std;

class Incomes :public BudgetItem
{
    vector<User> incomes;
    FileWithIncomes fileWithIncomes;

public:
    Incomes(string nameFileWithIncomes);
    void addIncome();
};

#endif // INCOMES_H
