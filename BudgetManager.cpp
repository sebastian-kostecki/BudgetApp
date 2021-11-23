#include "BudgetManager.h"

BudgetManager::BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
    : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses) {}

void BudgetManager::addIncome()
{
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    item = addContentToBudgetItem(fileWithIncomes);
    incomes.push_back(item);

    //zapisanie do pliku
}

void BudgetManager::addExpense()
{
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<< " << endl << endl;
    item = addContentToBudgetItem(fileWithExpenses);
    expenses.push_back(item);

    //zapisanie do pliku
}

Item BudgetManager::addContentToBudgetItem(FileWithBudgetItems fileWithBudgetItems)
{
    Item item;
    item.setId(fileWithBudgetItems.getLastItemId() + 1);
    item.setUserId(LOGGED_IN_USER_ID);
    item.setDate(getDateOfItem());
    item.setItem(getNameOfItem());
    item.setAmount(getAmountOfItem());
    return item;
}

int BudgetManager::getDateOfItem()
{
    int dateInt;
    switch (chooseDateTodayOrAnother())
    {
    case '1':
        dateInt = DateOperations::getDateTodayInInteger();
        break;
    case '2':
        string date = "";
        do
        {
            cout << "Podaj date (rrrr-mm-dd): ";
            date = AuxiliaryMethods::loadLine();
        } while (DateOperations::isDateCorrect(date) == false);
        date = DateOperations::removeDashesFromDate(date);
        dateInt = AuxiliaryMethods::convertStringToInt(date);
        break;
    }
    return dateInt;
}

string BudgetManager::getNameOfItem()
{
    string nameOfItem = "";
    cout << endl << "Podaj nazwe: ";
    nameOfItem = AuxiliaryMethods::loadLine();
    return nameOfItem;
}

double BudgetManager::getAmountOfItem()
{
    double amountOfItem = 0;
    string amountOfItemAsString = "";
    cout << "Podaj kwote: ";
    amountOfItemAsString = AuxiliaryMethods::loadLine();
    amountOfItem = AuxiliaryMethods::convertStringToDouble(amountOfItemAsString);
    return amountOfItem;
}

char BudgetManager::chooseDateTodayOrAnother()
{
    char choice;
    cout << "Czy dotyczy dnia dzisiejszego?" << endl;
    cout << "1. TAK" << endl;
    cout << "2. NIE" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadSign();
    while (choice != '1' && choice != '2')
    {
        cout << "Bledny wybor. Wybierz jeszcze raz: ";
        choice = AuxiliaryMethods::loadSign();
    }
    return choice;
}

void BudgetManager::displayIncomes()
{
    for (vector<Item>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr)
    {
        cout << itr -> getId() << endl;
        cout << DateOperations::changeIntegerDateToStringWithDashes(itr -> getDate()) << endl;
        cout << itr -> getItem() << endl;
        cout << itr -> getAmount() << endl;
    }
}