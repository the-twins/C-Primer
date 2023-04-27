// Modify the guessing program of Listing 8.4 so that it uses a more intelligent guessing
// strategy. For example, have the program initially guess 50, and have it ask the user
// whether the guess is high, low, or correct. If, say, the guess is low, have the next guess
// be halfway between 50 and 100, that is 75. If that guess is high, let the next guess be
// halfway between 75 and 50, and so on. Using this binary search strategy, the program
// quickly zeros in on the correct answer, at least if the user does not cheat.
#include <stdio.h>

int main(void)
{
    int mid = 50;
    int max = 101;
    int min = 0;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with 'h' if my guess is low, 'l' if my ");
    printf("guess is high and 'y' if my guess is right.\n");
    printf("Uh...is your number %d?\n", mid);
    while ((response = getchar()) != 'y')
    {
        if (response == 'h')
	{
	    min = mid;
	    printf("Well, then, is it %d?\n", mid += (max - min) / 2);
	}
	else if (response == 'l')
        {
	    max = mid;
            printf("Well, then, is it %d?\n", mid -= (max - min) / 2);
	}
        else if (response == 'y')

	    return 0;
	else
	    printf("Sorry, I understand only l, h or y. \n");
        while (getchar() != '\n')
       	    continue;       
    }	
    printf("I knew I could do it!\n");

    return 0;
}
