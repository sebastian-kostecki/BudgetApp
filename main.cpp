#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main() {
    BudgetApp budgetApp("users.xml");
    //budgetApp.registerUser();
    budgetApp.showUsers();
    return 0;
}

int main_test()
{
    BudgetApp budgetApp("users.xml");

    return 0;
}
