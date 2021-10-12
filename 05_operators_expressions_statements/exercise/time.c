// This program converts time in minutes to time in hours and minutes.
// Use #define or const to create a symbolic constant for 60. Use a while
// loop to allow the user to enter values repeatedly and terminate the loop
// if a value for the time of 0 or less is entered.

#include <stdio.h>
#define HOUR 60

int main(void)
{
    int min, hour;
    printf("This program converts time in minutes to time in hours and minutes");
    printf("\nEnter 0 to end the program.\n"); 
    printf("Please enter time in minutes.\n");
    scanf("%d", &min);
    while ( min > 0 ) 
    {
        printf("It is equal %d hours and %d minutes.\n",
                min / HOUR, min % HOUR);
        printf("Enter next value.\n");
        scanf("%d", &min);
    } 

    return 0;
}
