#include "DateOperations.h"

int DateOperations::getDateTodayInInteger()
{
    int dateInteger;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%Y%m%d", dateTime);
    dateInteger = AuxiliaryMethods::convertStringToInt(date);

    return dateInteger;
}

string DateOperations::getDateFromUser()
{
    string date = "";

    getline(cin, date);
    date.erase(4, 1);
    date.erase(6,1);

    return date;
}

int DateOperations::getNumberOfDaysCurrentMonth()
{
    int dayInSeconds = 24*60*60;
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    dateTime->tm_mon = dateTime->tm_mon + 1;
    dateTime->tm_mday = 1;
    timeInSeconds = mktime(dateTime);
    timeInSeconds = timeInSeconds - dayInSeconds;
    dateTime = localtime(&timeInSeconds);
    return dateTime->tm_mday;
}

int DateOperations::getNumberOfYearToday()
{
    int yearInt;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%Y", dateTime);
    yearInt = AuxiliaryMethods::convertStringToInt(date);
    return yearInt;
}

int DateOperations::getNumberOfMonthToday()
{
    int monthInt;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%m", dateTime);
    monthInt = AuxiliaryMethods::convertStringToInt(date);
    return monthInt;
}
