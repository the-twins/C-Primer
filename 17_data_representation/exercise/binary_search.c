// Write a function that takes three arguments: the name of an array of sorted integers, the
// number of elements of the array, and an integer to seek. The function returns the value
// 1 if the integer is in the array, and 0 if it isn't. Have the function use the binary search
// technique.
#include <stdio.h>
#include <stdlib.h>     // for rand()
#include <time.h>       // for srand()

#define MAX_AR 100

int find_in_array(int * numb_array, int numb, int find_numb);

int main(void)
{
    int numb_array[MAX_AR];
    int i, seek, top;
    int numb;
    int min;
    int temp = 0;
    int find_numb = 0;
    int check = 0;
    srand(time(NULL));
    printf("Enter the number of array elements(from 1 to 100):\n");
    scanf("%d", &numb);
    if(numb < 1 || numb > 100)
    {
        printf("You entered incorrect number. Bye.\n");
        return 1;
    }
    for(i = 0; i < numb; i++)
        numb_array[i] = rand() % MAX_AR;
    for(top = 0; top < numb - 1; top++)
        for(seek = top + 1; seek < numb; seek++)
            if(numb_array[top] > numb_array[seek])
            {
                temp = numb_array[top];
                numb_array[top] = numb_array[seek];
                numb_array[seek] = temp;
            }
    printf("\nYour array:\n");
    for(i = 0; i < numb; i++)
        printf("%d ", numb_array[i]);
    printf("\nEnter the number you want to find in the array(q to quit):\n");
    while((scanf("%d", &find_numb) == 1))
    {
        check = find_in_array(numb_array, numb, find_numb);
        if(check == 1)
            printf("This number is in the array.\n");
        else
            printf("This number is not in the array.\n");
        printf("Try again. Enter the number (q to quit)\n");
    }
    printf("Bye!\n");

    return 0;
}

int find_in_array(int * numb_array, int numb, int find_numb)
{
    int min, max, middle;
    for(min = 0, max = numb, middle = max/2; min <= max;)
    {
        if(find_numb == numb_array[middle])
            return 1;
        if(find_numb > numb_array[middle])
        {
            min = middle;
            middle = (min + max) / 2;
            if (middle == min)
                return 0;
        }
        else
        {
            max = middle;
            middle = (min + max) / 2;
            if (middle == max)
                return 0;
        }
    }
}
