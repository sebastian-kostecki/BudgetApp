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
    vector<Item> incomesCurrentMonth = incomes.selectBudgetItemsCurrentMonth();
    vector<Item> expensesCurrentMonth = expenses.selectBudgetItemsCurrentMonth();
    sort(incomesCurrentMonth.begin(), incomesCurrentMonth.end());
    sort(expensesCurrentMonth.begin(), expensesCurrentMonth.end());
    displayTitleOfBalanceCurrentMonth();
    displayBalance(incomesCurrentMonth, expensesCurrentMonth);
}

void UserBudget::displayBalancePreviousMonth()
{
    vector<Item> incomesPreviousMonth = incomes.selectBudgetItemsPreviousMonth();
    vector<Item> expensesPreviousMonth = expenses.selectBudgetItemsPreviousMonth();
    sort(incomesPreviousMonth.begin(), incomesPreviousMonth.end());
    sort(expensesPreviousMonth.begin(), expensesPreviousMonth.end());
    displayTitleOfBalancePreviousMonth();
    displayBalance(incomesPreviousMonth, expensesPreviousMonth);
}

void UserBudget::displayTitleOfBalanceCurrentMonth() {
    system("cls");
    cout << "                    BILANS OBECNEGO MIESIACA                   " << endl;
}

void UserBudget::displayTitleOfBalancePreviousMonth()
{
    system("cls");
    cout << "                  BILANS POPRZEDNIEGO MIESIACA                 " << endl;
}

void UserBudget::displayTitleOfBalanceChosenPeriod(string startingDate, string endDate)
{
    system("cls");
    cout << "        BILANS W OKRESIE OD "  << startingDate << " DO " << endDate << "          " << endl;
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
    cout << setw(11) << left << "BILANS:" <<  setw(10) << right << incomes.sumAmountOfBudgetItems(selectedIncomes) - expenses.sumAmountOfBudgetItems(selectedExpenses) << " zl" << endl;
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

void UserBudget::displayBalanceChosenPeriod()
{
    string startingDate = "", endDate = "";
    system("cls");
    do
    {
        cout << "Podaj date poczatkowa (rrrr-mm-dd): ";
        startingDate = AuxiliaryMethods::loadLine();
    } while (DateOperations::isDateCorrect(startingDate) == false);

    do
    {
        cout << "Podaj date koncowa (rrrr-mm-dd): ";
        endDate = AuxiliaryMethods::loadLine();
    } while (DateOperations::isDateCorrect(endDate) == false);

    vector<Item> incomesChosenPeriod = incomes.selectBudgetItemsChosenPeriod(startingDate, endDate);
    vector<Item> expensesChosenPeriod = expenses.selectBudgetItemsChosenPeriod(startingDate, endDate);

    sort(incomesChosenPeriod.begin(), incomesChosenPeriod.end());
    sort(expensesChosenPeriod.begin(), expensesChosenPeriod.end());

    displayTitleOfBalanceChosenPeriod(startingDate, endDate);
    displayBalance(incomesChosenPeriod, expensesChosenPeriod);
}
