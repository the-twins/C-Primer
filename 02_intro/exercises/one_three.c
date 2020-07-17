//The program calls a function named one_three(). This function should display the word one on one line, call a second function named two(), and then display the word three on one line. The function two() should display the word two on one line. The main() function should display the phrase starting now: befor calling one_three() and display done! after calling it.
#include <stdio.h>

void one_three(void);
void two(void);

int main(void)
{
    printf("starting now:\n");
    one_three(); 
    printf("done!\n");

    return 0;
}

void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}

void two(void)
{
    printf("two\n");
}
