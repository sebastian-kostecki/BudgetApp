#ifndef BUDGETITEM_H
#define BUDGETITEM_H

#include <iostream>
#include <vector>

#include "Item.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"

using namespace std;

class BudgetItem
{
protected:
    vector<Item> budgetItems;

    Item addContentToBudgetItem(int lastItemId, int loggedInUserId);
    int getDateOfItem();
    string getNameOfItem();
    double getAmountOfItem();
    char selectDateTodayOrAnother();

public:
    vector<Item> selectBudgetItemsCurrentMonth();
    vector<Item> selectBudgetItemsPreviousMonth();
    vector<Item> selectBudgetItemsChosenPeriod(string startingDate, string endDate);
    double sumAmountOfBudgetItems(vector<Item> items);
};

#endif // BUDGETITEM_H
