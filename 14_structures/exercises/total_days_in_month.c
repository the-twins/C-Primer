// Redo Rewiew Question 5, but make the argument the spelled-out name of the month
// instead of the month number. (Don't forget about a strcmp().) Test the function in a
// simple program.
#include <stdio.h>
#include <string.h>
#include "../../11_strings/lib.h"

#define ALL_YEAR 365
#define M 12

struct month {
    char name [10];
    char short_name[4];
    int days;
    int numb;
};

int count_days(const struct month year[], char * m);

int main(void)
{
    struct month year[12] = {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}
    };
    char enter_month[10];
    int numb;
    printf("Enter a month (January, February, March, April, May, June, July, August,"
           " September, October, November, December.)\n");
    while (s_gets(enter_month, 10) != NULL)
    {
        numb = count_days(year, enter_month);
        if(numb == 1)
        {
            printf("You enter the month name incorrectly. Try again (EOF to quit):\n");
            continue;
        }
        else
            printf("The total days in the year up to and including %s is %d.\n", enter_month, numb);
        printf("Try again (EOF to quit).\n");
    }

    return 0;
}

int count_days(const struct month year[], char * m)
{
    int total = 0;
    int i = 0;
    for(; strcmp(m, year[i].name) != 0; i++)
    {
        total += year[i].days;
        if (total > ALL_YEAR || i == M)
            return 1;
    }
    return total + year[i].days;
}
