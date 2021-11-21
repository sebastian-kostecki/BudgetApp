#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int integerNumber;
    istringstream iss(number);
    iss >> integerNumber;

    return integerNumber;
}
