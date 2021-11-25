#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <time.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperations
{

public:
    static int getDateTodayInInteger();
    static int getNumberOfDaysCurrentMonth();
    static int getNumberOfYearToday();
    static int getNumberOfMonthToday();
    static string removeDashesFromDate(string date);
    static string changeIntegerDateToStringWithDashes(int dateInt);
    static bool isDateCorrect(string date);
    static int getNumberOfDaysForChosenDate(int year, int month);
    static bool isDateBelongsToCurrentMonth(int dateInt);
    static bool isDateBelongsToPreviousMonth(int dateInt);
    static bool isDateBelongsToChosenPeriod(int dateInt, string startingDate, string endDate);
    static int getIntegerNumberOfYearFromDate(string date);
    static int getIntegerNumberOfMonthFromDate(string date);
    static int getIntegerNumberOfDaysFromDate(string date);
};

#endif // DATEOPERATIONS_H
