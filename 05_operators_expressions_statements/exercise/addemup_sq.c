// addemup1.c -- this program calculates how much money can you get if you receive
// $1 the first day, $4 the second day, $9 the third day, and so on (the sum of the 
// squares of the integers). The number of days you enter.

#include <stdio.h>

int main(void)
{
    int count, sum, day;

    count = 0;
    sum = 0;
    printf("Enter the number of days: "); 
    scanf("%d", &day);
    while (count++ < day)
    sum = sum + count * count;   
    printf("sum = %d\n", sum);

    return 0;
}
