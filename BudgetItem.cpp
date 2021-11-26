#include "BudgetItem.h"

Item BudgetItem::addContentToBudgetItem(int lastItemId, int loggedInUserId) {
    Item item;
    item.setId(lastItemId + 1);
    item.setUserId(loggedInUserId);
    item.setDate(getDateOfItem());
    item.setItem(getNameOfItem());
    item.setAmount(getAmountOfItem());
    return item;
}

int BudgetItem::getDateOfItem() {
    int dateInteger = 0;
    switch (selectDateTodayOrAnother()) {
    case '1':
        dateInteger = DateOperations::getDateTodayInInteger();
        cout << endl << "Data: " << DateOperations::changeIntegerDateToStringWithDashes(dateInteger) << endl;
        break;
    case '2':
        string dateString = "";
        do {
            cout << endl << "Podaj date (rrrr-mm-dd): ";
            dateString = AuxiliaryMethods::loadLine();
        } while (DateOperations::isDateCorrect(dateString) == false);
        dateString = DateOperations::removeDashesFromDate(dateString);
        dateInteger = AuxiliaryMethods::convertStringToInteger(dateString);
        break;
    }
    return dateInteger;
}

char BudgetItem::selectDateTodayOrAnother() {
    char choice;
    cout << "Czy dotyczy dnia dzisiejszego?" << endl;
    cout << "1. TAK" << endl;
    cout << "2. NIE" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadSign();
    while (choice != '1' && choice != '2') {
        cout << "Bledny wybor. Wybierz jeszcze raz: ";
        choice = AuxiliaryMethods::loadSign();
    }
    return choice;
}

string BudgetItem::getNameOfItem() {
    string nameOfItem = "";
    cout << "Podaj nazwe: ";
    nameOfItem = AuxiliaryMethods::loadLine();
    return nameOfItem;
}

double BudgetItem::getAmountOfItem() {
    double amountOfItem = 0;
    string amountOfItemAsString = "";
    cout << "Podaj kwote: ";
    amountOfItemAsString = AuxiliaryMethods::loadLine();
    amountOfItem = AuxiliaryMethods::convertStringToDouble(amountOfItemAsString);
    return amountOfItem;
}

vector<Item> BudgetItem::selectSortedBudgetItemsCurrentMonth() {
    vector<Item> currentMonthBudgetItems;
    for (vector<Item>::iterator itr = budgetItems.begin(); itr != budgetItems.end(); ++itr) {
        if (DateOperations::isDateBelongsToCurrentMonth(itr -> getDate()))
            currentMonthBudgetItems.push_back(*itr);
    }
    sort(currentMonthBudgetItems.begin(), currentMonthBudgetItems.end());
    return currentMonthBudgetItems;
}

vector<Item> BudgetItem::selectSortedBudgetItemsPreviousMonth() {
    vector<Item> previousMonthBudgetItems;
    for (vector<Item>::iterator itr = budgetItems.begin(); itr != budgetItems.end(); ++itr) {
        if (DateOperations::isDateBelongsToPreviousMonth(itr -> getDate()))
            previousMonthBudgetItems.push_back(*itr);
    }
    sort(previousMonthBudgetItems.begin(), previousMonthBudgetItems.end());
    return previousMonthBudgetItems;
}

vector<Item> BudgetItem::selectSortedBudgetItemsChosenPeriod(string startingDate, string endDate) {
    vector<Item> chosenPeriodBudgetItems;
    for (vector<Item>::iterator itr = budgetItems.begin(); itr != budgetItems.end(); ++itr) {
        if (DateOperations::isDateBelongsToChosenPeriod(itr -> getDate(), startingDate, endDate))
            chosenPeriodBudgetItems.push_back(*itr);
    }
    sort(chosenPeriodBudgetItems.begin(), chosenPeriodBudgetItems.end());
    return chosenPeriodBudgetItems;
}

double BudgetItem::sumAmountOfBudgetItems(vector<Item> items) {
    double sum = 0;
    for (vector<Item>::iterator itr = items.begin(); itr != items.end(); ++itr) {
        sum += itr -> getAmount();
    }
    return sum;
}
