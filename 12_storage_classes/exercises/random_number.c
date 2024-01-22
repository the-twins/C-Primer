// Write a program that generates a list of 100 random numbers in the range 1-10
// in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11,
// "Character Strings and String Functions," to type int. In this case, just sort the numbers
// themselves.)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define RANGE 10

void sort_n(int * numb);

int main(void)
{
    unsigned int start;
    int numb[SIZE];
    int t;
    printf("Enter 100 to generate 100 random numbers and 0 to quit: ");
    scanf("%d", &start);
    while(start == SIZE)
    {
        srand((unsigned int) time(0));
        for(t = 0; t <= SIZE; t++)
        {
	    numb[t] = rand() % RANGE + 1;
            printf("%d ", numb[t]);
	}
	sort_n(numb);
	printf("Enter 100 to generate or 0 to quit:");
	scanf("%d", &start);
    }

    return 0;
}

void sort_n(int * numb)
{
    printf("\nSorted list: \n");
    int temp;
    int top, seek, i;
    for(top = 0; top < SIZE-1; top++)
        for(seek = top + 1; seek < SIZE; seek++)
            if(numb[top] < numb[seek])
            {
                temp = numb[top];
		numb[top] = numb[seek];
		numb[seek] = temp;
            }
    for (i = 0; i < SIZE; i++)
        printf("%d ", numb[i]);
    printf("\n");
}
