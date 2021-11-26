#include "FileWithExpenses.h"

FileWithExpenses::FileWithExpenses(string nameFileWithExpenses)
    : FileWithBudgetItems(nameFileWithExpenses), LABEL_OF_EXPENSES("expenses"), LABEL_OF_EXPENSE("expense"), LABEL_OF_EXPENSE_ID("expenseId") {}

void FileWithExpenses::addBudgetItemToFile(Item item) {
    CMarkup xml;
    if (xml.Load(NAME_FILE_WITH_BUDGET_ITEMS)) {
        xml.FindElem(LABEL_OF_EXPENSES);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_EXPENSE);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_EXPENSE_ID, AuxiliaryMethods::convertIntegerToString(item.getId()));
        xml.AddElem(LABEL_OF_USER_ID, AuxiliaryMethods::convertIntegerToString(item.getUserId()));
        xml.AddElem(LABEL_OF_DATE, DateOperations::changeIntegerDateToStringWithDashes(item.getDate()));
        xml.AddElem(LABEL_OF_ITEM, item.getItem());
        xml.AddElem(LABEL_OF_AMOUNT, AuxiliaryMethods::convertDoubleToString(item.getAmount()));
        xml.Save(NAME_FILE_WITH_BUDGET_ITEMS);
    } else {
        xml.AddElem(LABEL_OF_EXPENSES);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_EXPENSE);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_EXPENSE_ID, AuxiliaryMethods::convertIntegerToString(item.getId()));
        xml.AddElem(LABEL_OF_USER_ID, AuxiliaryMethods::convertIntegerToString(item.getUserId()));
        xml.AddElem(LABEL_OF_DATE, DateOperations::changeIntegerDateToStringWithDashes(item.getDate()));
        xml.AddElem(LABEL_OF_ITEM, item.getItem());
        xml.AddElem(LABEL_OF_AMOUNT, AuxiliaryMethods::convertDoubleToString(item.getAmount()));
        xml.Save(NAME_FILE_WITH_BUDGET_ITEMS);
    }
    lastItemId++;
}
