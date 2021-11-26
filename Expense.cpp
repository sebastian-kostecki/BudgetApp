#include "Expense.h"

Expense::Expense(string nameFileWithExpenses, int loggedInUserId) : fileWithExpenses(nameFileWithExpenses) {
    budgetItems = fileWithExpenses.loadBudgetItemFromFile(loggedInUserId);
}

void Expense::addExpense(int loggedInUserId) {
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<< " << endl << endl;
    item = addContentToBudgetItem(fileWithExpenses.getLastItemId(), loggedInUserId);
    budgetItems.push_back(item);
    fileWithExpenses.addBudgetItemToFile(item);
}
