#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>

#include "Markup.h"
#include "FileWithBudgetItems.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
#include "Item.h"

using namespace std;

class FileWithExpenses :public FileWithBudgetItems {
    const string LABEL_OF_EXPENSES;
    const string LABEL_OF_EXPENSE;
    const string LABEL_OF_EXPENSE_ID;

public:
    FileWithExpenses(string nameFileWithExpenses);
    void addBudgetItemToFile(Item item);
};

#endif // FILEWITHEXPENSES_H
