#include "DateOperations.h"

int DateOperations::getDateInInteger()
{
    int dateInteger;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%Y%m%d.", dateTime);
    dateInteger = AuxiliaryMethods::convertStringToInt(date);

    return dateInteger;
}

int DateOperations::getDateInIntegerFromUser()
{
    int dateInteger = 0;
    string date = "";

    getline(cin, date);
    date.erase(4, 1);
    date.erase(6,1);
    dateInteger = AuxiliaryMethods::convertStringToInt(date);

    return dateInteger;
}
