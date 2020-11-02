// The program sets a type double variable to 1.0/3.0 and a type float variable
// to 1.0/3.0. Display each result three times - once showing four digits to 
// the right of the decimal, once showing 12 digits to the right of the
// decimal, and once showing 16 digits to the right of decimal. Also have the   
// program include float.h and display the values of FLT_DIG and DBL_DIG. 
#include <stdio.h>
#include <float.h>

int main(void)
{
    float a = 1.0 / 3.0;
    double b = 1.0 / 3.0;

    printf("The first result: %.4f and %.4f.\n", a, b);
    printf("The second result: %.12f and %.12f.\n", a, b);
    printf("The third result: %.16f and %.16f.\n", a, b);
    printf("Float precision = %d. Double precision = %d.\n", FLT_DIG, DBL_DIG);

    return 0;
}  
