#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "Item.h"
#include "AuxiliaryMethods.h"
#include "FileWithBudgetItems.h"
#include "DateOperations.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_IN_USER_ID;
    vector<Item> incomes;
    vector<Item> expenses;
    FileWithBudgetItems fileWithIncomes;

    Item giveDataOfIncome();
    char chooseDateTodayOrAnother();
    bool isDateCorrect(string date);

public:
    BudgetManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses);
    void addIncome();

    void displayIncomes();
};

#endif // BUDGETMANAGER_H
