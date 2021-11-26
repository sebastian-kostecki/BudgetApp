#include "Income.h"

Income::Income(string nameFileWithIncomes, int loggedInUserId) : fileWithIncomes(nameFileWithIncomes) {
    budgetItems = fileWithIncomes.loadBudgetItemFromFile(loggedInUserId);
};

void Income::addIncome(int loggedInUserId) {
    Item item;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    item = addContentToBudgetItem(fileWithIncomes.getLastItemId(), loggedInUserId);
    budgetItems.push_back(item);
    fileWithIncomes.addBudgetItemToFile(item);
    cout << endl << "Przychod dodano" << endl << endl;
    system("pause");
}
