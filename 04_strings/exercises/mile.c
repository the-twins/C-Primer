// The program asks the user to enter the number of miles traveled and the
// number of gallons of gasoline consumed.It should then calculateand display
// the miles-per-gallon value, showing one placeto the right of the decimal.
// Next, using the fact that one gallon is about 3.785 liters and one mile is
// about 1.609 kilometers, it should convert the mile-per-gallon value to a 
// liters-per-100-km value, the usual European way of expressing fuel 
// consumption, and display the result, showing one place to the right of the
// decimal. Note that the U.S. scheme measuresthe distance traveled per amount
// of fuel (higher is better), whereas the European scheme measures the amount
// of fuel per distance (lower is better). Use symbolic constants (using const
// or #define) for the two conversion factors.
#include <stdio.h>
#define LITER 3.785
#define KM 1.609

int main(void)
{
    float mile;
    float gallon;

    printf("Enter the number of miles traveled.\n");
    scanf("%f", &mile);
    printf("Enter the number of gallons of gasoline consumed.\n");
    scanf("%f", &gallon);
    printf("It amounts %.1f mile-per-gallon.\n", mile / gallon);
    printf("It amounts %.1f liters-per-100-km.\n",
            mile * LITER * 100 / gallon * KM);

    return 0;
}  
