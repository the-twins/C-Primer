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

int main(void)
{
    unsigned int start;
    int numb, a, b, c, d, e, f, g, h, i, j, t;
    printf("Enter 1000 to generate 1000 random numbers and 0 to quit: ");
    scanf("%d", &start);
    while(start == SIZE)
    {
        srand((unsigned int) time(0));
        for(t = 0; t < SIZE; t++)
        {
	    numb = rand() % RANGE + 1;
            if(numb == 1)
                a++;
            if(numb == 2)
                b++;
            if(numb == 3)
                c++;
	    if(numb == 4)
                d++;
	    if(numb == 5)
                e++;
            if(numb == 6)
                f++;
            if(numb == 7)
                g++;
            if(numb == 8)
                h++;
            if(numb == 9)
                i++;
            if(numb == 10)
                j++;
        }
        printf("'1' = %d\n'2' = %d\n'3' = %d\n'4' = %d\n'5' = %d\n", a, b, c, d, e);
	printf("'6' = %d\n'7' = %d\n'8' = %d\n'9' = %d\n'10' = %d\n", f, g, h, i, j);
        printf("Enter 1000 to generate 1000 random numbers and 0 to quit: ");
	scanf("%d", &start);
    }

    return 0;
}
