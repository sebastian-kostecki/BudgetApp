#include "BudgetManager.h"

BudgetManager::BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
    : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses) {
    incomes = fileWithIncomes.loadBudgetItemFromFile(LOGGED_IN_USER_ID);
    expenses = fileWithExpenses.loadBudgetItemFromFile(LOGGED_IN_USER_ID);
}

void BudgetManager::addIncome() {
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    item = addContentToBudgetItem(fileWithIncomes.getLastItemId());
    incomes.push_back(item);
    fileWithIncomes.addIncomeToFile(item);
}

void BudgetManager::addExpense() {
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<< " << endl << endl;
    item = addContentToBudgetItem(fileWithExpenses.getLastItemId());
    expenses.push_back(item);
    fileWithExpenses.addExpenseToFile(item);
}

Item BudgetManager::addContentToBudgetItem(int lastItemId) {
    Item item;
    item.setId(lastItemId + 1);
    item.setUserId(LOGGED_IN_USER_ID);
    item.setDate(getDateOfItem());
    item.setItem(getNameOfItem());
    item.setAmount(getAmountOfItem());
    return item;
}

int BudgetManager::getDateOfItem() {
    int dateInt;
    switch (chooseDateTodayOrAnother()) {
    case '1':
        dateInt = DateOperations::getDateTodayInInteger();
        break;
    case '2':
        string date = "";
        do {
            cout << "Podaj date (rrrr-mm-dd): ";
            date = AuxiliaryMethods::loadLine();
        } while (DateOperations::isDateCorrect(date) == false);
        date = DateOperations::removeDashesFromDate(date);
        dateInt = AuxiliaryMethods::convertStringToInt(date);
        break;
    }
    return dateInt;
}

string BudgetManager::getNameOfItem() {
    string nameOfItem = "";
    cout << endl << "Podaj nazwe: ";
    nameOfItem = AuxiliaryMethods::loadLine();
    return nameOfItem;
}

double BudgetManager::getAmountOfItem() {
    double amountOfItem = 0;
    string amountOfItemAsString = "";
    cout << "Podaj kwote: ";
    amountOfItemAsString = AuxiliaryMethods::loadLine();
    amountOfItem = AuxiliaryMethods::convertStringToDouble(amountOfItemAsString);
    return amountOfItem;
}

char BudgetManager::chooseDateTodayOrAnother() {
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

void BudgetManager::displayIncomes() {
    for (vector<Item>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
        cout << itr -> getId() << endl;
        cout << DateOperations::changeIntegerDateToStringWithDashes(itr -> getDate()) << endl;
        cout << itr -> getItem() << endl;
        cout << itr -> getAmount() << endl << endl;
    }
}

void BudgetManager::displayBalanceCurrentMonth() {
    //double sumOfIncomes = 0, sumOfExpenses = 0;
    vector<Item> incomesCurrentMonth = selectCurrentMonthIncomes();
    vector<Item> expensesCurrentMonth = selectCurrentMonthExpenses();
    //sortowanie wektorow
    sort(incomesCurrentMonth.begin(), incomesCurrentMonth.end());
    sort(expensesCurrentMonth.begin(), expensesCurrentMonth.end());
    displayBudgetItems(incomesCurrentMonth);
    cout << "-------" << endl;
    displayBudgetItems(expensesCurrentMonth);
}

vector<Item> BudgetManager::selectCurrentMonthIncomes() {
    vector<Item> incomesCurrentMonth;
    for (vector<Item>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
        if (DateOperations::isDateBelongsToCurrentMonth(itr -> getDate()))
            incomesCurrentMonth.push_back(*itr);
    }
    return incomesCurrentMonth;
}

vector<Item> BudgetManager::selectCurrentMonthExpenses() {
    vector<Item> expensesCurrentMonth;
    for (vector<Item>::iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
        if (DateOperations::isDateBelongsToCurrentMonth(itr -> getDate()))
            expensesCurrentMonth.push_back(*itr);
    }
    return expensesCurrentMonth;
}

void BudgetManager::displayBudgetItems(vector<Item> budgetItem)
{
    for (vector<Item>::iterator itr = budgetItem.begin(); itr != budgetItem.end(); ++itr)
    {
        displayBudgetItem(*itr);
    }
}

void BudgetManager::displayBudgetItem(Item item)
{
    cout << DateOperations::changeIntegerDateToStringWithDashes(item.getDate()) << " ";
    cout << item.getItem() << " ";
    cout << item.getAmount() << " zl" << endl;
}
