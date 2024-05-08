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
int total_days_leap(const struct mnth[], int m, int d);
int total_days_non_leap(const struct mnth[], int m, int d);

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
    printf("Please enter a year:\n");
    scanf("%d", &ent_year);
    printf("Please enter a month:\n");
    scanf("%s", enter_month);
    printf("Please enter a date:\n");
    scanf("%d", &enter_day);
    if(ent_year < 1)
    {
        printf("You entered the year incorrectly.\n");
        return 1;
    }
    if(n = atoi(enter_month))
    {
        if(n > 0 && n <= M)
            f_month = n;
        else
        {
            printf("You enterd the month incorrectly.\n");
            return 1;
        }
    }
    else
    {
        for(int i = 0; i < 10; i++)
            enter_month[i] = toupper(enter_month[i]);   
        f_month = find_month(year, enter_month);
    }
    if(year[f_month - 1].days < enter_day || enter_day < 1)
    {
        printf("You entered the date incorrectly.\n");
        return 1;
    }
    if((ent_year % 4 == 0 && ent_year % 100 != 0) || ent_year % 400 == 0)
        printf("The total days in the year up to and including %s "
               "month is %d.\n", enter_month, total_days_leap(year, f_month, enter_day));
    else
        printf("The total days in the year up to and including %s month"
               " is %d.\n", enter_month, total_days_non_leap(year, f_month, enter_day));

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
}

int total_days_leap(const struct mnth year[], int m, int d)
{
    int total = 0;
    int i;
    if(m > 2)
    {
        for(i = 0; i < m - 1; i++)
            total += year[i].days;
        return total + d + DAY_IN_LEAP;
        
    }
    else
    {
        for(i = 0; i < m - 1; i++)
            total += year[i].days;
        return total + d;
    }	
}

int total_days_non_leap(const struct mnth year[], int m, int d)
{
    int total = 0;
    int i;
    for(i = 0; i < m - 1; i++)
        total += year[i].days;
    return total + d;
}
