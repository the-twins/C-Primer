// The program asks the user to enter the number of miles traveled and the
// number of gallons of gasoline consumed. It should then calculate and display
// the miles-per-gallon value, showing one place to the right of the decimal.
// Next, using the fact that one gallon is about 3.785 liters and one mile is
// about 1.609 kilometers, it should convert the mile-per-gallon value to a 
// liters-per-100-km value, the usual European way of expressing fuel 
// consumption, and display the result, showing one place to the right of the
// decimal. Note that the U.S. scheme measures the distance traveled per amount
// of fuel (higher is better), whereas the European scheme measures the amount
// of fuel per distance (lower is better). Use symbolic constants (using const
// or #define) for the two conversion factors.
#include <stdio.h>
#define LITER_IN_GALLON 3.785
#define KM_IN_MILE 1.609

int main(void)
{
    float mile;
    float gallon;
    float mile_per_gallon;

    printf("Enter the number of miles traveled.\n");
    scanf("%f", &mile);
    printf("Enter the number of gallons of gasoline consumed.\n");
    scanf("%f", &gallon);
    mile_per_gallon = mile / gallon;
    printf("It amounts %.1f mile-per-gallon.\n", mile_per_gallon);
    printf("It amounts %.1f liters-per-100-km.\n",
            LITER_IN_GALLON * 100 /(mile_per_gallon * KM_IN_MILE));

    return 0;
}  
