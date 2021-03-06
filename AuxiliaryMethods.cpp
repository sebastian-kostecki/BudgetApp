#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadSign() {
    string input = "";
    char sign  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int AuxiliaryMethods::convertStringToInteger(string number) {
    int integerNumber;
    istringstream iss(number);
    iss >> integerNumber;
    return integerNumber;
}

double AuxiliaryMethods::convertStringToDouble(string number) {
    double integerNumber;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] == ',')
            number.replace(i, 1, ".");
    }
    istringstream iss(number);
    iss >> integerNumber;
    return integerNumber;
}

string AuxiliaryMethods::convertIntegerToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDoubleToString(double number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertToAmountBeforeDot(double amount) {
    int amountBeforeDot = amount;
    return amountBeforeDot;
}
string AuxiliaryMethods::convertToAmountAfterDot(double amount) {
    string const SYMBOL_OF_TWO_ZERO = "00";
    int amountAftedDot = amount * 100;
    amountAftedDot %= 100;
    if (amountAftedDot == 0)
        return SYMBOL_OF_TWO_ZERO;
    else
        return convertIntegerToString(amountAftedDot);
}
