#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods {
public:
    static string loadLine();
    static char loadSign();
    static int convertStringToInteger(string number);
    static double convertStringToDouble(string number);
    static string convertIntegerToString(int number);
    static string convertDoubleToString(double number);
    static int convertToAmountBeforeDot(double amount);
    static string convertToAmountAfterDot(double amount);
};

#endif // AUXILIARYMETHODS_H
