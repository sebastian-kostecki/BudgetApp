#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

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

    Item addContentToBudgetItem(FileWithBudgetItems fileWithBudgetItems);
    char chooseDateTodayOrAnother();
    int getDateOfItem();
    string getNameOfItem();
    double getAmountOfItem();

public:
    BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses);
    void addIncome();
    void addExpense();

    void displayIncomes();
};

#endif // BUDGETMANAGER_H
