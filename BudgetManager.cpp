#include "BudgetManager.h"

BudgetManager::BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
    : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(nameFileWithIncomes) {}

void BudgetManager::addIncome()
{
    Item item;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    item = giveDataOfIncome();

    incomes.push_back(item);

    //zapisanie do pliku
}

Item BudgetManager::giveDataOfIncome()
{
    Item item;

    item.setId(fileWithIncomes.getLastItemId());
    item.setUserId(LOGGED_IN_USER_ID);

    switch (chooseDateTodayOrAnother())
    {
    case '1':
        item.setDate(DateOperations::getDateTodayInInteger());
        break;
    case '2':
        string date = "";
        do
        {
            cout << "Wpisz date date uzyskania przychodu (rrrr-mm-dd): ";
            date = AuxiliaryMethods::loadLine();
        } while (isDateCorrect(date) == false);
        item.setDate(AuxiliaryMethods::convertStringToInt(date));
        break;
    }

    cout << "Podaj nazwe przychodu: ";
    item.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj kwote przychodu: ";
    item.setAmount(AuxiliaryMethods::convertStringToDouble(AuxiliaryMethods::loadLine()));

    return item;
}

char BudgetManager::chooseDateTodayOrAnother()
{
    char choice;
    cout << "Czy przychod dotyczy dnia dzisiejszego?" << endl;
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

bool BudgetManager::isDateCorrect(string date)
{
    int yearInt = 0, monthInt = 0, daysInt = 0;
    string yearString = "", monthString = "", daysString = "";
    yearString = date.substr(0, 4);
    yearInt = atoi(yearString.c_str());
    monthString = date.substr(5, 2);
    monthInt = atoi(monthString.c_str());
    daysString = date.substr(8, 2);
    daysInt = atoi(daysString.c_str());

    if ((yearInt >= 2000 && yearInt <= DateOperations::getNumberOfYearToday()) == false)
        return false;
    if ((monthInt > 0 && monthInt <= DateOperations::getNumberOfMonthToday()) == false)
        return false;
    if ((daysInt > 0 && daysInt <= DateOperations::getNumberOfDaysCurrentMonth()) ==  false)
        return false;
    return true;
}

void BudgetManager::displayIncomes()
{
    for (vector<Item>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr)
    {
        cout << itr -> getId() << endl;
        cout << itr -> getDate() << endl;
        cout << itr -> getItem() << endl;
        cout << itr -> getAmount() << endl;
    }
}
