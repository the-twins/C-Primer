// Daphne invests $100 at 10% simple interest. (That is, every year, the 
// investment earns an interest equal to 10% of the original investment.) 
// Deirdre invests $100 at 5% interest compounded annually. (That is, interest 
// is 5% of the current balance, including previous addition of interest.) 
// Write a program that finds how many years it takes for the value of Deirdre’s 
// investment to exceed the value of Daphne’s investment. Also show the two 
// values at that time.
#include <stdio.h>

#define DEPOSIT 100.0
#define DAPHNE_PERCENT 0.1
#define DEIRDRE_PERCENT 0.05

int main(void)
{
    float daphne, deirdre;
    int years;

    for (daphne = DEPOSIT, deirdre = DEPOSIT, years = 1; deirdre <= daphne; years++)
    {
        daphne = daphne + DEPOSIT * DAPHNE_PERCENT;
        deirdre = deirdre + deirdre * DEIRDRE_PERCENT;
    }
    printf("Deirdre's balance will be $%.2f and Daphne's balance will be $%.2f after %d years.\n", deirdre, daphne, years);

    return 0;
}
