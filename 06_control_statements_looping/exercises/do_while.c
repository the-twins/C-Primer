// Write a program that creates an eight-element array of ints and sets the 
// elements to the first eight powers of 2 and then prints the values. Use 
// a for loop to set the values, and, for variety, use a do while loop to 
// display the values.
#include <stdio.h>

#define SIZE 8

int main(void)
{
    int index;
    int numbers[SIZE];
    int number = 1;

    for (index = 0; index < SIZE; index++)
    {   
        numbers[index] = number;
        number = number * 2;
    }
    
    index = 0;
    do
    {
        printf("%d ", numbers[index]);
        index++;
    } while (index < SIZE);
    printf("\n");
   
    return 0;
}
