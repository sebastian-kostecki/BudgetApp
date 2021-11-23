#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>

#include "Markup.h"
#include "FileWithBudgetItems.h"

using namespace std;

class FileWithExpenses :public FileWithBudgetItems
{
    const string LABEL_OF_EXPENSES;
    const string LABEL_OF_EXPENSE_ID;

public:
    FileWithExpenses(string nameFileWithExpenses);
};

#endif // FILEWITHEXPENSES_H
