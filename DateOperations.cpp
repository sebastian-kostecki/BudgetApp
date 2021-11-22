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
