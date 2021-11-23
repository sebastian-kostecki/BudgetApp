#include "FileWithBudgetItems.h"

FileWithBudgetItems::FileWithBudgetItems(string nameFileWithBudgetItems)
    : NAME_FILE_WITH_BUDGET_ITEMS(nameFileWithBudgetItems), LABEL_OF_USER_ID("userId"), LABEL_OF_DATE("date"), LABEL_OF_ITEM("item"), LABEL_OF_AMOUNT("amount")
{
    lastItemId = 0;
}

int FileWithBudgetItems::getLastItemId()
{
    return lastItemId;
}
