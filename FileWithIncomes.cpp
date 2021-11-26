#include "FileWithIncomes.h"

FileWithIncomes::FileWithIncomes(string nameFileOfIncomes)
    : FileWithBudgetItems(nameFileOfIncomes), LABEL_OF_INCOMES("incomes"), LABEL_OF_INCOME("income"), LABEL_OF_INCOME_ID("incomeId") {}

void FileWithIncomes::addBudgetItemToFile(Item item) {
    CMarkup xml;
    if (xml.Load(NAME_FILE_WITH_BUDGET_ITEMS)) {
        xml.FindElem(LABEL_OF_INCOMES);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_INCOME);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_INCOME_ID, AuxiliaryMethods::convertIntegerToString(item.getId()));
        xml.AddElem(LABEL_OF_USER_ID, AuxiliaryMethods::convertIntegerToString(item.getUserId()));
        xml.AddElem(LABEL_OF_DATE, DateOperations::changeIntegerDateToStringWithDashes(item.getDate()));
        xml.AddElem(LABEL_OF_ITEM, item.getItem());
        xml.AddElem(LABEL_OF_AMOUNT, AuxiliaryMethods::convertDoubleToString(item.getAmount()));
        xml.Save(NAME_FILE_WITH_BUDGET_ITEMS);
    } else {
        xml.AddElem(LABEL_OF_INCOMES);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_INCOME);
        xml.IntoElem();
        xml.AddElem(LABEL_OF_INCOME_ID, AuxiliaryMethods::convertIntegerToString(item.getId()));
        xml.AddElem(LABEL_OF_USER_ID, AuxiliaryMethods::convertIntegerToString(item.getUserId()));
        xml.AddElem(LABEL_OF_DATE, DateOperations::changeIntegerDateToStringWithDashes(item.getDate()));
        xml.AddElem(LABEL_OF_ITEM, item.getItem());
        xml.AddElem(LABEL_OF_AMOUNT, AuxiliaryMethods::convertDoubleToString(item.getAmount()));
        xml.Save(NAME_FILE_WITH_BUDGET_ITEMS);
    }
    lastItemId++;
}
