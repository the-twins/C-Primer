// The program asks for your first name, your last name, and then prints the
// names in the format last, first.
#include <stdio.h>

int main(void)
{
    char first_name [40];
    char last_name [40];

    printf("What is your first name?\n");
    scanf("%s", first_name);
    printf("What is your last name?\n");
    scanf("%s", last_name);
    printf("%s %s.\n", last_name, first_name);

    return 0;
}
