#include "DateOperations.h"

int DateOperations::getDateTodayInInteger() {
    int dateInteger;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%Y%m%d", dateTime);
    dateInteger = AuxiliaryMethods::convertStringToInteger(date);

    return dateInteger;
}

string DateOperations::removeDashesFromDate(string date) {
    date.erase(4, 1);
    date.erase(6,1);
    return date;
}

int DateOperations::getNumberOfYearToday() {
    int yearInt;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%Y", dateTime);
    yearInt = AuxiliaryMethods::convertStringToInteger(date);
    return yearInt;
}

int DateOperations::getNumberOfMonthToday() {
    int monthInt;
    char date[64];
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);
    strftime(date, sizeof(date), "%m", dateTime);
    monthInt = AuxiliaryMethods::convertStringToInteger(date);
    return monthInt;
}

string DateOperations::changeIntegerDateToStringWithDashes(int dateInt) {
    string dateStr = AuxiliaryMethods::convertIntegerToString(dateInt);
    dateStr.insert(4, "-");
    dateStr.insert(7, "-");
    return dateStr;
}

bool DateOperations::isDateCorrect(string date) {
    int yearInt = 0, monthInt = 0, daysInt = 0;
    string yearString = "", monthString = "", daysString = "";
    yearString = date.substr(0, 4);
    yearInt = atoi(yearString.c_str());
    monthString = date.substr(5, 2);
    monthInt = atoi(monthString.c_str());
    daysString = date.substr(8, 2);
    daysInt = atoi(daysString.c_str());

    if (yearInt < 2000 || yearInt > getNumberOfYearToday()) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    } else if (yearInt == getNumberOfYearToday() && (monthInt < 1 || monthInt > getNumberOfMonthToday())) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    } else if (yearInt != getNumberOfYearToday() && (monthInt < 1 || monthInt > 12)) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    } else if (daysInt < 0 || daysInt > getNumberOfDaysForChosenDate(yearInt, monthInt)) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    }
    return true;
}

int DateOperations::getNumberOfDaysForChosenDate(int year, int month) {
    int numberOfMonthsDaysChosenDate = 0;
    year = year - 1900;
    month = month - 1;
    int dayInSeconds = 24*60*60;
    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);

    if (month < 11) {
        dateTime->tm_year = year;
        dateTime->tm_mon = month + 1;
    } else {
        dateTime->tm_year = year + 1;
        dateTime->tm_mon = 0;
    }
    dateTime->tm_mday = 1;

    timeInSeconds = mktime(dateTime);
    timeInSeconds = timeInSeconds - dayInSeconds;
    dateTime = localtime(&timeInSeconds);
    numberOfMonthsDaysChosenDate = dateTime->tm_mday;
    return dateTime->tm_mday;
}

bool DateOperations::isDateBelongsToCurrentMonth(int dateInt) {
    int yearInt = 0, monthInt = 0;
    string yearString = "", monthString = "";
    string date = AuxiliaryMethods::convertIntegerToString(dateInt);

    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);

    yearString = date.substr(0,4);
    yearInt = atoi(yearString.c_str()) - 1900;
    monthString = date.substr(4,2);
    monthInt = atoi(monthString.c_str()) - 1;

    if (dateTime->tm_year == yearInt && dateTime->tm_mon == monthInt)
        return true;
    else
        return false;
}

bool DateOperations::isDateBelongsToPreviousMonth(int dateInt) {
    int yearInt = 0, monthInt = 0;
    string yearString = "", monthString = "";
    string date = AuxiliaryMethods::convertIntegerToString(dateInt);

    time_t timeInSeconds;
    struct tm *dateTime;
    time(&timeInSeconds);
    dateTime = localtime(&timeInSeconds);

    yearString = date.substr(0,4);
    yearInt = atoi(yearString.c_str()) - 1900;
    monthString = date.substr(4,2);
    monthInt = atoi(monthString.c_str()) - 1;

    if (dateTime->tm_year == yearInt && dateTime->tm_mon - 1 == monthInt)
        return true;
    else
        return false;
}

bool DateOperations::isDateBelongsToChosenPeriod(int dateInt, string startingDate, string endDate) {
    string dateString = changeIntegerDateToStringWithDashes(dateInt);
    if (getIntegerNumberOfYearFromDate(dateString) < getIntegerNumberOfYearFromDate(startingDate) || getIntegerNumberOfYearFromDate(dateString) > getIntegerNumberOfYearFromDate(endDate))
        return false;
    else if (getIntegerNumberOfYearFromDate(dateString) == getIntegerNumberOfYearFromDate(startingDate) && getIntegerNumberOfMonthFromDate(dateString) < getIntegerNumberOfMonthFromDate(startingDate))
        return false;
    else if (getIntegerNumberOfYearFromDate(dateString) == getIntegerNumberOfYearFromDate(endDate) && getIntegerNumberOfMonthFromDate(dateString) > getIntegerNumberOfMonthFromDate(endDate))
        return false;
    else if (getIntegerNumberOfYearFromDate(dateString) == getIntegerNumberOfYearFromDate(startingDate) && getIntegerNumberOfMonthFromDate(dateString) == getIntegerNumberOfMonthFromDate(startingDate)
             && getIntegerNumberOfDaysFromDate(dateString) < getIntegerNumberOfDaysFromDate(startingDate))
        return false;
    else if (getIntegerNumberOfYearFromDate(dateString) == getIntegerNumberOfYearFromDate(endDate) && getIntegerNumberOfMonthFromDate(dateString) == getIntegerNumberOfMonthFromDate(endDate)
             && getIntegerNumberOfDaysFromDate(dateString) > getIntegerNumberOfDaysFromDate(endDate))
        return false;
    return true;
}

int DateOperations::getIntegerNumberOfYearFromDate(string date) {
    string yearString = date.substr(0,4);
    int yearInteger = atoi(yearString.c_str()) - 1900;
    return yearInteger;
}

int DateOperations::getIntegerNumberOfMonthFromDate(string date) {
    string monthString = date.substr(5, 2);
    int monthInteger = atoi(monthString.c_str());
    return monthInteger;
}

int DateOperations::getIntegerNumberOfDaysFromDate(string date) {
    string daysString = date.substr(8, 2);
    int daysInteger = atoi(daysString.c_str());
    return daysInteger;
}

string DateOperations::getStartingDate() {
    string startingDate = "";
    do {
        cout << "Podaj date poczatkowa (rrrr-mm-dd): ";
        startingDate = AuxiliaryMethods::loadLine();
    } while (DateOperations::isDateCorrect(startingDate) == false);
    return startingDate;
}

string DateOperations::getEndDate() {
    string endDate = "";
    do {
        cout << "Podaj date koncowa    (rrrr-mm-dd): ";
        endDate = AuxiliaryMethods::loadLine();
    } while (DateOperations::isDateCorrect(endDate) == false);
    return endDate;
}

bool DateOperations::isDateLater(string startingDate, string endDate) {
    int yearStartingDate = getIntegerNumberOfYearFromDate(startingDate);
    int monthStartingDate = getIntegerNumberOfMonthFromDate(startingDate);
    int daysStartingDate = getIntegerNumberOfDaysFromDate(startingDate);
    int yearEndDate = getIntegerNumberOfYearFromDate(endDate);
    int monthEndDate = getIntegerNumberOfMonthFromDate(endDate);
    int daysEndDate = getIntegerNumberOfDaysFromDate(endDate);

    if (yearStartingDate > yearEndDate) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    } else if (yearStartingDate == yearEndDate && monthStartingDate > monthEndDate) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    } else if (yearStartingDate == yearEndDate && monthStartingDate == monthEndDate && daysStartingDate >= daysEndDate) {
        cout << "Podana data jest nieprawidlowa!" << endl;
        return false;
    }
    return true;
}
