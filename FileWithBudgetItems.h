#ifndef FILEWITHBUDGETITEMS_H
#define FILEWITHBUDGETITEMS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Item.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"

using namespace std;

class FileWithBudgetItems {
protected:
    int lastItemId;
    const string NAME_FILE_WITH_BUDGET_ITEMS;
    const string LABEL_OF_USER_ID;
    const string LABEL_OF_DATE;
    const string LABEL_OF_ITEM;
    const string LABEL_OF_AMOUNT;

public:
    FileWithBudgetItems(string nameFileWithBudgetItems);
    int getLastItemId();
    vector<Item> loadBudgetItemFromFile(int loggedUserId);
    virtual void addBudgetItemToFile(Item item) = 0;
};

#endif // FILEWITHBUDGETITEMS_H
