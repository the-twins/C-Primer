// Devise a function chline(ch, i, j) that prints the requested character in columns i
// through j. Test it in a simple driver.
#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    char ch;
    int i, j;
    printf("Enter one character and two numbers.\n");
    while (scanf("%c %d %d", &ch, &i, &j) == 3)
    {
        chline(ch, i, j);
        printf("Try again. Enter one character and two numbers.\n");
	getchar();
    }
    printf("Bye!\n");

    return 0;
}

void chline(char ch, int i, int j)
{
    int n;

    for(n = 1; n < i; n++)
        putchar(' ');
    for(n = i; n <= j; n++)
        putchar(ch);
    putchar('\n');
}
