#include "Expenses.h"

Expenses::Expenses(string nameFileWithExpenses, int loggedInUserId) : fileWithExpenses(nameFileWithExpenses) {};

void Expenses::addExpense(int loggedInUserId)
{
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<< " << endl << endl;
    item = addContentToBudgetItem(fileWithExpenses.getLastItemId(), loggedInUserId);
    budgetItems.push_back(item);
    fileWithExpenses.addBudgetItemToFile(item);
}
