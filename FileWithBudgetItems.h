#ifndef FILEWITHBUDGETITEMS_H
#define FILEWITHBUDGETITEMS_H

#include <iostream>

#include "Markup.h"

using namespace std;

class FileWithBudgetItems
{
    int lastItemId;
    const string NAME_FILE_WITH_BUDGET_ITEMS;
    const string LABEL_OF_USER_ID;
    const string LABEL_OF_DATE;
    const string LABEL_OF_ITEM;
    const string LABEL_OF_AMOUNT;

public:
    FileWithBudgetItems(string nameFileWithBudgetItems);
    int getLastItemId();
};

#endif // FILEWITHBUDGETITEMS_H
