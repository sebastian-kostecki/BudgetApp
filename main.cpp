#include <iostream>

#include "BudgetApp.h"

using namespace std;

int _main() {
    BudgetApp budgetApp("users.xml", "incomes.xml", "expenses.xml");
    //budgetApp.registerUser();
    budgetApp.showUsers();
    //budgetApp.loginUser();
    return 0;
}
















//test FileWithUsers
#include "User.h"
#include "FileWithUsers.h"



//test UserManager
#include "UserManager.h"

int user_main() {
    UserManager manager("users-test.xml");
    //manager.setLoggedUserId(15);
    //manager.changeUserPassword();
    manager.loginUser();
    //manager.showUsers();
    return 0;
}



//test BudgetManager
#include "BudgetManager.h"

int manager_main()
{
    BudgetManager budget(1, "incomes-test.xml", "expenses-test.xml");
    //budget.addIncome();
    //budget.addExpense();
    //budget.addIncome();
    //budget.addExpense();
    //budget.displayIncomes();
    //budget.addExpense();
    budget.displayBalanceCurrentMonth();
}

//testy UserBudget
#include "UserBudget.h"

int main()
{
    UserBudget budget(1, "incomes-test.xml", "expenses-test.xml");
    budget.displayBalanceCurrentMonth();
}

