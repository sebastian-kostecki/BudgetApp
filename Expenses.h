#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithExpenses.h"
#include "Turnover.h"

using namespace std;

class Expenses :public Turnover
{
    vector<User> expenses;
    FileWithExpenses fileWithExpenses;
};

#endif // EXPENSES_H
