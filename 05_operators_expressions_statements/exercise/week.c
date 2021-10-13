// This program asks the user to enter the number of days and converts that value
// to weeks and days. The program has 'while' to allow the user to repeatedly
// enter day values and the program stops when the user enters a nonpositive value,
// such as 0 or -20.
#include <stdio.h>

#define WEEK 7

int main(void)
{
    int day;
    printf("This program asks the user to enter the number of days and then "
           "converts that value to weeks and days.\n");
    printf("The program stops when the user enters a nonpositive value.\n");
    printf("Enter the number of days.\n");
    scanf("%d", &day);
    while ( day > 0)
    {
        printf("%d days are %d weeks, %d days.\n", day, day / WEEK, day % WEEK);
        printf("Enter the next number of days.\n");
        scanf("%d", &day);
    }

    return 0;
}
