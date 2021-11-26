#include "UserBudget.h"

UserBudget::UserBudget(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
    :LOGGED_IN_USER_ID(loggedInUserId), incomes(nameFileWithIncomes, LOGGED_IN_USER_ID), expenses(nameFileWithExpenses, LOGGED_IN_USER_ID) {};

void UserBudget::addIncome() {
    incomes.addIncome(LOGGED_IN_USER_ID);
}

void UserBudget::addExpense() {
    expenses.addExpense(LOGGED_IN_USER_ID);
}

void UserBudget::displayBalanceCurrentMonth() {
    system("cls");
    cout << "                    BILANS OBECNEGO MIESIACA                   " << endl;
    displayBalance(incomes.selectSortedBudgetItemsCurrentMonth(), expenses.selectSortedBudgetItemsCurrentMonth());
}

void UserBudget::displayBalancePreviousMonth() {
    system("cls");
    cout << "                  BILANS POPRZEDNIEGO MIESIACA                 " << endl;
    displayBalance(incomes.selectSortedBudgetItemsPreviousMonth(), expenses.selectSortedBudgetItemsPreviousMonth());
}

void UserBudget::displayBalanceChosenPeriod() {
    system("cls");
    string startingDate = DateOperations::getStartingDate();
    string endDate = DateOperations::getEndDate();

    system("cls");
    cout << "        BILANS W OKRESIE OD "  << startingDate << " DO " << endDate << "          " << endl;
    displayBalance(incomes.selectSortedBudgetItemsChosenPeriod(startingDate, endDate), expenses.selectSortedBudgetItemsChosenPeriod(startingDate, endDate));
}

void UserBudget::displayBalance(vector<Item> selectedIncomes, vector<Item> selectedExpenses) {
    cout << "---------------------------------------------------------------" << endl;
    cout << "                            PRZYCHODY                          " << endl << endl;
    displayBudgetItems(selectedIncomes);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "                             WYDATKI                           " << endl << endl;
    displayBudgetItems(selectedExpenses);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << setw(11) << left << "PRZYCHODY:" << setw(10) << right << incomes.sumAmountOfBudgetItems(selectedIncomes) << " zl" << endl;
    cout << setw(11) << left << "WYDATKI:" <<  setw(10) << right << expenses.sumAmountOfBudgetItems(selectedExpenses) << " zl" << endl << endl;
    cout << setw(11) << left << "BILANS:" <<  setw(10) << right << incomes.sumAmountOfBudgetItems(selectedIncomes) - expenses.sumAmountOfBudgetItems(selectedExpenses) << " zl" << endl << endl;
    system("pause");
}

void UserBudget::displayBudgetItems(vector<Item> budgetItem) {
    int counter = 1;
    cout << "-Lp.------Data-----------------Nazwa------------------Kwota----" << endl << endl;
    for (vector<Item>::iterator itr = budgetItem.begin(); itr != budgetItem.end(); ++itr) {
        displayItem(*itr, counter);
        counter++;
    }
}

void UserBudget::displayItem(Item item, int counter) {
    cout << setw(4) << right << counter << ".| ";
    cout << DateOperations::changeIntegerDateToStringWithDashes(item.getDate()) << "  ";
    cout << setw(30) << left << item.getItem() << " ";
    cout << setw(10) << right << item.getAmount() << " zl" << endl;
}
