#ifndef USERBUDGET_H
#define USERBUDGET_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Income.h"
#include "Expense.h"

using namespace std;

class UserBudget
{
    const int LOGGED_IN_USER_ID;
    Income incomes;
    Expense expenses;

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
