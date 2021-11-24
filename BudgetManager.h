#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Item.h"
#include "AuxiliaryMethods.h"
#include "FileWithBudgetItems.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "DateOperations.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_IN_USER_ID;
    vector<Item> incomes;
    vector<Item> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Item addContentToBudgetItem(int lastItemId);
    char chooseDateTodayOrAnother();
    int getDateOfItem();
    string getNameOfItem();
    double getAmountOfItem();
    vector<Item> selectCurrentMonthIncomes(double &sumOfIncomes);
    vector<Item> selectCurrentMonthExpenses(double &sumOfExpenses);
    void displayBudgetItem(Item item, int counter);
    void displayBudgetItems(vector<Item> budgetItem);

public:
    BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses);
    void addIncome();
    void addExpense();
    void displayBalanceCurrentMonth();

    void displayIncomes();
};

#endif // BUDGETMANAGER_H
