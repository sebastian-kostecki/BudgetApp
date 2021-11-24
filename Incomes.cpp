#include "Incomes.h"

Incomes::Incomes(string nameFileWithIncomes, int loggedInUserId) : fileWithIncomes(nameFileWithIncomes) {
    budgetItems = fileWithIncomes.loadBudgetItemFromFile(loggedInUserId);
};

void Incomes::addIncome(int loggedInUserId)
{
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    item = addContentToBudgetItem(fileWithIncomes.getLastItemId(), loggedInUserId);
    budgetItems.push_back(item);
    fileWithIncomes.addBudgetItemToFile(item);
}
