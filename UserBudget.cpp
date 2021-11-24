#include "UserBudget.h"

UserBudget::UserBudget(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
    :LOGGED_IN_USER_ID(loggedInUserId), incomes(nameFileWithIncomes, LOGGED_IN_USER_ID), expenses(nameFileWithExpenses) {};

void UserBudget::addIncome()
{
    incomes.addIncome(LOGGED_IN_USER_ID);
}
