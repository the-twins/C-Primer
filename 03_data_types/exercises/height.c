// This program asks you to enter your height in inches and then displays
// your height in centimeters. 1 inch = 2.54 centimeters.
#include <stdio.h>

int main(void)
{
    float inch;

    printf("Enter your height in inches: ");
    scanf("%f", &inch);
    printf("Your height is %.2f centimeters.\n", inch * 2.54);

    return 0;
}  
    
