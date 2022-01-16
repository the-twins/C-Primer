// Chuckie Lucky won a million dollars (after taxes), which he places in an 
// account that earns 8% a year. On the last day of each year, Chuckie 
// withdraws $100,000. Write a program that finds out how many years it takes 
// for Chuckie to empty his account.
#include <stdio.h>

#define PRIZE 1000000
#define PERCENT 0.08
#define WITHDRAW 100000

int main(void)
{
    int money;
    int years;

    for (money = PRIZE, years = 0; money >= 0; years++)
    {
        money = money + money * PERCENT - WITHDRAW;
    }
    printf("Money will run out in %d years.\n", years);

    return 0;
}
