// Thise program asks you to enter your height in inches and then displays
// your height in centimeters. 1 inche = 2.54 centimeters.
#include <stdio.h>

int main(void)
{
    float inche;
    float height;

    printf("Enter your height in inches: ");
    scanf("%f", &inche);
    printf("Your height is %.2f centimeters.\n", height = inche * 2.54);

    return 0;
}  
    
