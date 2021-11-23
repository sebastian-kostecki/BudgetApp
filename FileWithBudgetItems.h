#ifndef FILEWITHBUDGETITEMS_H
#define FILEWITHBUDGETITEMS_H

#include <iostream>

#include "Markup.h"

using namespace std;

class FileWithBudgetItems
{
    int lastItemId;
    const string NAME_FILE_WITH_BUDGET_ITEMS;

public:
    FileWithBudgetItems(string nameFileWithBudgetItems);
    int getLastItemId();
};

#endif // FILEWITHBUDGETITEMS_H
