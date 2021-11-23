#include "FileWithBudgetItems.h"

FileWithBudgetItems::FileWithBudgetItems(string nameFileWithBudgetItems) : NAME_FILE_WITH_BUDGET_ITEMS(nameFileWithBudgetItems)
{
    lastItemId = 0;
}

int FileWithBudgetItems::getLastItemId()
{
    return lastItemId;
}
