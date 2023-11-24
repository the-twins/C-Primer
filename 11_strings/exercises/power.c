// Write a power-law program that works on a command-line basis. The first command-line
// argument should be the type double number to be raised to a certain power, and the
// second argument should be the integer power.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n;
    double numb;
    double power = 1;
    numb = atof(argv[1]);
    i = atoi(argv[2]);
    for(n = 1; n <= i; n++)
        power *= numb;
    printf("%.2f to the %d th power is equal to %.2f\n", numb, i, power);

    return 0;
}
        
        
