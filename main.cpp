#include <iostream>

#include "BudgetApp.h"

using namespace std;

int _main() {
    BudgetApp budgetApp("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!(budgetApp.isUserLogin())) {
            switch (budgetApp.selectOptionFromMainMenu()) {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                budgetApp.displayStatementWhenUserMakeWrongChoice();
                break;
            }
        } else {
            switch (budgetApp.selectOptionFormUserMenu()) {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                budgetApp.addExpense();
                break;
            case '3':
                budgetApp.displayBalanceCurrentMonth();
                break;
            case '4':
                budgetApp.displayBalancePreviousMonth();
                break;
            case '5':
                budgetApp.displayBalanceChosenPeriod();
                break;
            case '6':
                budgetApp.changeUserPassword();
                break;
            case '9':
                budgetApp.logoutUser();
                break;
            default:
                budgetApp.displayStatementWhenUserMakeWrongChoice();
                break;
            }
        }
    }
    return 0;
}


//testy UserBudget
#include "UserBudget.h"

int main() {
    UserBudget budget(1, "incomes-test.xml", "expenses-test.xml");
    //budget.displayBalanceCurrentMonth();
    budget.displayBalancePreviousMonth();
    //budget.displayBalanceChosenPeriod();
    //budget.addExpense();
    //budget.addIncome();
}

