// This program asks the user to enter a height in centimeters and then displays
// the height in centimeters and in feet and inches. The program stops when user
// enters a nonpositive value.
#include <stdio.h>

#define CM_IN_INCH 2.54
#define INCH_IN_FEET 12

int main(void)
{
     float cm, inch;
     int feet;
     printf("Enter a height in centimeters: ");
     scanf("%f", &cm);
     while (cm > 0)
     {
         inch = cm / CM_IN_INCH;
         feet = inch / INCH_IN_FEET;
         printf("%.1f cm = %d feet, %.1f inches.\n", cm, feet, inch - feet * INCH_IN_FEET);
         printf("Enter a height in centimeters (<=0 to quit): ");
         scanf("%f", &cm);
     }
     printf("Bye.\n");

     return 0;
}
