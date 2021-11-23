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

double AuxiliaryMethods::convertStringToDouble(string number)
{
    double integerNumber;

    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] == ',')
            number.replace(i, 1, ".");
    }
    istringstream iss(number);
    iss >> integerNumber;

    return integerNumber;
}

string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
