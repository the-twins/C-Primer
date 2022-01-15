// Consider these two infinite series:
// 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
// 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
// Write a program that evaluates running totals of these two series up to 
// some limit of number of terms. 
// Hint: –1 times itself an odd number of times is –1, and –1 times itself an 
// even number of times is 1. Have the user enter the limit interactively; let 
// a zero or negative value terminate input. Look at the running totals after 
// 100 terms, 1000 terms, 10,000 terms. Does either series appear to be 
// converging to some value?
#include <stdio.h>

int main(void)
{
    float number, max_number, sum_1, sum_2;
    printf("Enter the limit integer: ");
    scanf("%f", &max_number);
    while (max_number > 0)
    {
        sum_1 = 0;
        for (number = 1.0; number <= max_number; number++)
            sum_1 = sum_1 + 1.0 / number;
        sum_2 = sum_1;
        for (number = 2; number <= max_number; number = number + 2)
            sum_2 = sum_2 - 2.0 / number;
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... = %.2f.\n", sum_1);
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... = %.2f.\n", sum_2);
        printf("Enter the limit integer: ");
        scanf("%f", &max_number);
    }
    return 0;
}
