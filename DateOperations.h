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
};

#endif // DATEOPERATIONS_H
