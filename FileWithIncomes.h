#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>

#include "Markup.h"
#include "FileWithBudgetItems.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
#include "Item.h"

using namespace std;

class FileWithIncomes :public FileWithBudgetItems {
    const string LABEL_OF_INCOMES;
    const string LABEL_OF_INCOME;
    const string LABEL_OF_INCOME_ID;

public:
    FileWithIncomes(string nameFileOfIncomes);
    void addBudgetItemToFile(Item item);
};

#endif // FILEWITHINCOMES_H
