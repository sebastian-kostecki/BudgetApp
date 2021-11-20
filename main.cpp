#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main() {
    BudgetApp budgetApp("users.xml");
    budgetApp.registerUser();
    return 0;
}
