#include "UserBudget.h"

UserBudget::UserBudget(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
    :LOGGED_IN_USER_ID(loggedInUserId), incomes(nameFileWithIncomes), expenses(nameFileWithExpenses) {};

void UserBudget::addIncome()
{
    incomes.addIncome();
}

