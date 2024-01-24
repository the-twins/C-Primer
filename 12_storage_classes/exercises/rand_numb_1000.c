// Write a program that generates 1000 random numbers in the range 1-10. Don't save or
// print the numbers, but do print how many times each number was produced. Have the
// program do this for 10 different seed values. Do the numbers apper in equal amounts?
// You can use the function from this chapter or the ANSI C rand() and srand() 
// function, which follow the same format that our functions do. this is one way to
// examine the randomness of paticular random-number generator.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define RANGE 10
#define SEEDS 10

void print_ar(int ar[], int n);

int main(void)
{
    int start;
    int t, numb;
    int ar[RANGE] = {0,0,0,0,0,0,0,0,0,0};
    printf("Generate %d random numbers ranging 1 - %d %d times: \n", SIZE, RANGE, SEEDS);
    printf(" 1   2   3   4   5   6   7   8   9   10\n");
    printf("----------------------------------------\n");
    srand((unsigned int) time(0));
    for(start = 0; start < SEEDS; start++)
    {
        for(t = 0; t < SIZE; t++)
        {
	    numb = rand() % RANGE + 1;
	    ar[numb - 1]++;
	}
        print_ar(ar, RANGE);
	printf("\n");
	for(t = 0; t < RANGE; t++)
            ar[t] = 0;
    }

    return 0;
}

void print_ar(int ar[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%3d ", ar[i]);
}
