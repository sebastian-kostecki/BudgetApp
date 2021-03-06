#include "FileWithBudgetItems.h"

FileWithBudgetItems::FileWithBudgetItems(string nameFileWithBudgetItems)
    : NAME_FILE_WITH_BUDGET_ITEMS(nameFileWithBudgetItems), LABEL_OF_USER_ID("userId"), LABEL_OF_DATE("date"), LABEL_OF_ITEM("item"), LABEL_OF_AMOUNT("amount") {
    lastItemId = 0;
}

int FileWithBudgetItems::getLastItemId() {
    return lastItemId;
}

vector<Item> FileWithBudgetItems::loadBudgetItemFromFile(int loggedUserId) {
    Item item;
    vector<Item> items;
    CMarkup xml;

    if (xml.Load(NAME_FILE_WITH_BUDGET_ITEMS)) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()) {
            xml.IntoElem();
            xml.FindElem();
            item.setId(AuxiliaryMethods::convertStringToInteger(xml.GetData()));
            lastItemId = item.getId();
            xml.FindElem();
            item.setUserId(AuxiliaryMethods::convertStringToInteger(xml.GetData()));
            xml.FindElem();
            item.setDate(AuxiliaryMethods::convertStringToInteger(DateOperations::removeDashesFromDate(xml.GetData())));
            xml.FindElem();
            item.setItem(xml.GetData());
            xml.FindElem();
            item.setAmount(AuxiliaryMethods::convertStringToDouble(xml.GetData()));
            if (loggedUserId == item.getUserId())
                items.push_back(item);
            xml.OutOfElem();
        }
    }
    return items;
}
