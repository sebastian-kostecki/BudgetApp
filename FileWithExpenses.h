#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>

#include "Markup.h"
#include "BudgetManager.h"

using namespace std;

class FileWithExpenses :public FileWithBudgetItems
{
    const string LABEL_OF_EXPENSES;
    const string LABEL_OF_EXPENS_ID;
};

#endif // FILEWITHEXPENSES_H
