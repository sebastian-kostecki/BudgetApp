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
    static string getDateFromUser();
    static int getNumberOfDaysCurrentMonth();
    static int getNumberOfYearToday();
    static int getNumberOfMonthToday();
};

#endif // DATEOPERATIONS_H
