#include "Incomes.h"

Incomes::Incomes(string nameFileWithIncomes) : fileWithIncomes(nameFileWithIncomes) {};

void Incomes::addIncome()
{
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    //item = addContentToBudgetItem(fileWithIncomes.getLastItemId());
    //incomes.push_back(item);
    //fileWithIncomes.addBudgetItemToFile(item);
}

/*
Item BudgetManager::addContentToBudgetItem(int lastItemId) {
    Item item;
    item.setId(lastItemId + 1);
    item.setUserId(LOGGED_IN_USER_ID);
    item.setDate(getDateOfItem());
    item.setItem(getNameOfItem());
    item.setAmount(getAmountOfItem());
    return item;
}
*/
