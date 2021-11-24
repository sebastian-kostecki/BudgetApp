#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithIncomes.h"
#include "Turnover.h"

using namespace std;

class Incomes :public Turnover
{
    vector<User> incomes;
    FileWithIncomes fileWithIncomes;
};

#endif // INCOMES_H
