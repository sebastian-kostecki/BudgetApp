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
    vector<Item> incomesCurrentMonth = incomes.selectBudgetItemCurrentMonth();
    vector<Item> expensesCurrentMonth = expenses.selectBudgetItemCurrentMonth();
    sort(incomesCurrentMonth.begin(), incomesCurrentMonth.end());
    sort(expensesCurrentMonth.begin(), expensesCurrentMonth.end());
    displayTitleOfBalanceCurrentMonth();
    displayBalance(incomesCurrentMonth, expensesCurrentMonth);
}

void UserBudget::displayTitleOfBalanceCurrentMonth() {
    cout << "                    BILANS OBECNEGO MIESIACA                   " << endl;
}

void UserBudget::displayBalance(vector<Item> selectedIncomes, vector<Item> selectedExpenses) {
    double sumOfIncomes = BudgetItem::sumAmountOfBudgetItems(selectedIncomes);
    double sumOfExpenses = BudgetItem::sumAmountOfBudgetItems(selectedExpenses);

    cout << "---------------------------------------------------------------" << endl;
    cout << "                            PRZYCHODY                          " << endl << endl;
    displayBudgetItems(selectedIncomes);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "                             WYDATKI                           " << endl << endl;
    displayBudgetItems(selectedExpenses);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << setw(11) << left << "PRZYCHODY:" << setw(10) << right << sumOfIncomes << " zl" << endl;
    cout << setw(11) << left << "WYDATKI:" <<  setw(10) << right << sumOfExpenses << " zl" << endl << endl;
    cout << setw(11) << left << "BILANS:" <<  setw(10) << right << sumOfIncomes - sumOfExpenses << " zl" << endl;
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

