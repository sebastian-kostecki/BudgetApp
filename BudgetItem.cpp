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
    int dateInteger;
    switch (selectDateTodayOrAnother()) {
    case '1':
        dateInteger = DateOperations::getDateTodayInInteger();
        break;
    case '2':
        string dateString = "";
        do {
            cout << "Podaj date (rrrr-mm-dd): ";
            dateString = AuxiliaryMethods::loadLine();
        } while (DateOperations::isDateCorrect(dateString) == false);
        dateString = DateOperations::removeDashesFromDate(dateString);
        dateInteger = AuxiliaryMethods::convertStringToInt(dateString);
        break;
    }
    return dateInteger;
}

string BudgetItem::getNameOfItem() {
    string nameOfItem = "";
    cout << endl << "Podaj nazwe: ";
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
