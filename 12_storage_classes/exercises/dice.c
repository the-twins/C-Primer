// Write a program that behaves like the modification of Listing 12.13, which we discussed
// after showing the output of Listing 12.13. That is, have the program produce output like
// the following:
//
// Enter the number of sets; enter q to stop: 18
// How many sides and how many dice? 6 3
// Here are 18 sets of 3 6-sides throws.
//   12  10  6  9  8  14  8  15  9  14  12  17  11  7  10
//   13  8  14
// How many sets? Enter q to stop: q
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollem(int set, int dice, int sides);

int main(void)
{
    int dice, sides, set;
    printf("Enter the number of sets (q to stop): ");
    while(scanf("%d", &set) == 1 && set > 0)
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        if(sides < 2)
        {
            printf("Needs at least 2 sides. Bye.\n");
            break;
        } 
        if(dice < 1)
        {
            printf("Need at least 1 die. Bye.\n");
            break;
        }
	rollem(set, dice, sides);
        printf("Enter the number of sets(q to stop): ");
    }

    return 0;
}

void rollem(int set, int dice, int sides)
{
    int numb[set];
    int t, d, one;
    for(t = 0; t < set; t++)
        numb[t] = 0;
    srand((unsigned int) time(0));
    for (t = 0; t < set; t ++)
    {
        for(d = 0; d < dice; d++) 
            one += rand() % sides + 1;
	numb[t] = one;
	one = 0;
    }
    printf("Here are %d sets of %d %d-sides throws.\n",set, dice, sides);
    for(t = 0; t < set; t++)
        printf("%d ", numb[t]);
    printf("\n");
}
