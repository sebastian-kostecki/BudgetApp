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

string DateOperations::removeDashesFromDate(string date)
{
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

string DateOperations::changeIntegerDateToStringWithDashes(int dateInt)
{
    string dateStr = AuxiliaryMethods::convertIntegerToString(dateInt);
    dateStr.insert(4, "-");
    dateStr.insert(7, "-");
    return dateStr;
}

bool DateOperations::isDateCorrect(string date)
{
    int yearInt = 0, monthInt = 0, daysInt = 0;
    string yearString = "", monthString = "", daysString = "";
    yearString = date.substr(0, 4);
    yearInt = atoi(yearString.c_str());
    monthString = date.substr(5, 2);
    monthInt = atoi(monthString.c_str());
    daysString = date.substr(8, 2);
    daysInt = atoi(daysString.c_str());

    if ((yearInt >= 2000 && yearInt <= DateOperations::getNumberOfYearToday()) == false)
    {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    }
    if ((monthInt > 0 && monthInt <= DateOperations::getNumberOfMonthToday()) == false)
    {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    }
    if ((daysInt > 0 && daysInt <= DateOperations::getNumberOfDaysCurrentMonth()) ==  false)
    {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    }
    return true;
}
