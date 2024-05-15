// Write a program that prompts the user to enter the day, month, and year. The month
// can be a month number, a month name, or a month abbreviation. The program then
// should return the total number of days in the year up through the given day. (Do take
// leap year into account.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DAY_IN_LEAP 1
#define M 12

struct mnth {
    char name[10];
    char short_name[4];
    int days;
    int numb;
};

int find_month(const struct mnth[], char * m);
int total_days(const struct mnth[], int m, int d);

int main(void)
{
    struct mnth year[12] = {
        {"JANUARY","JAN", 31, 1},
        {"FEBRUARY","FEB", 28, 2},
        {"MARCH","MAR", 31, 3},
        {"APRIL","APR", 30, 4},
        {"MAY","MAY", 31, 5},
        {"JUNE","JUN", 30, 6},
        {"JULY","JUL", 31, 7},
        {"AUGUST","AUG", 31, 8},
        {"SEPTEMBER","SEP", 30, 9},
        {"OCTOBER","OCT", 31, 10},
        {"NOVEMBER","NOV", 30, 11},
        {"DECEMBER","DEC", 31, 12}
    };
    char enter_month[10];
    int f_month = 0;
    int enter_day = 0;
    int ent_year = 0;
    int n = 0;
    int tot = 0;
    _Bool year_leap;
    printf("Please enter a year:\n");
    scanf("%d", &ent_year);
    printf("Please enter a month:\n");
    scanf("%s", enter_month);
    printf("Please enter a date:\n");
    scanf("%d", &enter_day);
    year_leap = ((ent_year % 4 == 0 && ent_year % 100 != 0) || ent_year % 400 == 0);
    if(ent_year < 1)
    {
        printf("You entered the year incorrectly.\n");
        return 1;
    }
    if(n = atoi(enter_month))
        f_month = n;
    else
    {
        for(int i = 0; i < 10; i++)
            enter_month[i] = toupper(enter_month[i]);
        f_month = find_month(year, enter_month);
    }
    if(f_month < 1 || f_month > M)
    {
        printf("You entered the month incorrectly.\n");
        return 1;
    }
    if(year[f_month - 1].days < enter_day || enter_day < 1)
    {
	if (!(year_leap && f_month == 2 && enter_day == 29))
        {
            printf("You entered the date incorrectly.\n");
            return 1;
	}
    }
    if(year_leap)
    {
	if(f_month > 2)
	{
            tot = total_days(year, f_month, enter_day) + 1;
            printf("The total days in the year up to and including %s "
                   "month is %d.\n", enter_month, tot);
	}
        else
            printf("The total days in the year up to and including %s "
                   "month is %d.\n", enter_month, total_days(year, f_month, enter_day));
    }
    else
        printf("The total days in the year up to and including %s month"
               " is %d.\n", enter_month, total_days(year, f_month, enter_day));
    return 0;
}

int find_month(const struct mnth year[], char * m)
{
    int i;
    for(i = 0; i < M; i++)
    {
        if((strcmp(m, year[i].name) == 0) || (strcmp(m, year[i].short_name) == 0))
            return i + 1;
    }
    if(i == M)
        return 13;
}

int total_days(const struct mnth year[], int m, int d)
{
    int total = 0;
    int i;
    for(i = 0; i < m - 1; i++)
        total += year[i].days;
    return total + d;
}
