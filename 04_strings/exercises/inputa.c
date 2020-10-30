// The program reads in a floating-point number and prints it first in 
// decimal-point notation and then in exponential notation. Have the output
// use the following formats (the number of digits shown in the exponent
// may be differentfor your system):
// a. The input is 21.3 or 2.1e+001.
// b. The input is +21.290 or 2.129E+001.
#include <stdio.h>

int main(void)
{
    float a = 21.290;

    printf("The a is %.1f or %.1e\n", a, a);
    printf("The a is %+.3f or %.3E\n", a, a);

    return 0;
} 
