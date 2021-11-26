#ifndef USERBUDGET_H
#define USERBUDGET_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class UserBudget
{
    const int LOGGED_IN_USER_ID;
    Incomes incomes;
    Expenses expenses;

    void displayBalance(vector<Item> selectedIncomes, vector<Item> selectedExpenses);
    void displayBudgetItems(vector<Item> budgetItem);
    void displayItem(Item item, int counter);

public:
    UserBudget(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses);
    void addIncome();
    void addExpense();
    void displayBalanceCurrentMonth();
    void displayBalancePreviousMonth();
    void displayBalanceChosenPeriod();
};

#endif // USERBUDGET_H
