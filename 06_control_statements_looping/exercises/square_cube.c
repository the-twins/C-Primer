// Write a program that prints a table with each line giving an integer, its 
// square, and its cube. Ask the user to input the lower and upper limits for 
// the table. Use a for loop.
#include <stdio.h>

int main(void)
{
    int num, min, max;
    
    printf("Please enter lower and upper limits integers: ");
    scanf("%d %d", &min, &max);
    printf("    n   n squared   n cubed\n");

    for (num = min; num <= max; num++)
        printf("%5d %6d %11d\n", num, num * num, num * num * num);

    return 0;
}
