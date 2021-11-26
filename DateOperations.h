#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <time.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperations {
    static int getNumberOfYearToday();
    static int getNumberOfMonthToday();
    static int getNumberOfDaysForChosenDate(int year, int month);
    static int getIntegerNumberOfYearFromDate(string date);
    static int getIntegerNumberOfMonthFromDate(string date);
    static int getIntegerNumberOfDaysFromDate(string date);

public:
    static int getDateTodayInInteger();
    static string removeDashesFromDate(string date);
    static string changeIntegerDateToStringWithDashes(int dateInt);
    static bool isDateCorrect(string date);
    static bool isDateBelongsToCurrentMonth(int dateInt);
    static bool isDateBelongsToPreviousMonth(int dateInt);
    static bool isDateBelongsToChosenPeriod(int dateInt, string startingDate, string endDate);
    static string getStartingDate();
    static string getEndDate();
};

#endif // DATEOPERATIONS_H
