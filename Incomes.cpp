#include "Incomes.h"

Incomes::Incomes(string nameFileWithIncomes) : fileWithIncomes(nameFileWithIncomes) {};

void Incomes::addIncome(int loggedInUserId)
{
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    item = addContentToBudgetItem(fileWithIncomes.getLastItemId(), loggedInUserId);
    budgetItems.push_back(item);
    fileWithIncomes.addBudgetItemToFile(item);
}
