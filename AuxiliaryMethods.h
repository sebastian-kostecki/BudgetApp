#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods {
public:
    static string loadLine();
    static int convertStringToInt(string number);
    static char loadSign();
    static double convertStringToDouble(string number);
    static string convertIntegerToString(int number);
    static string convertDoubleNumberToString(double number);
};

#endif // AUXILIARYMETHODS_H
