// Write a program that echoes the command-line arguments in reverse word order. That
// is, if the command-line arguments are see you later, the program should print later
// you see.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int count;
    for(count = argc - 1; count > 0; count--)
        printf("%s ", argv[count]);
    printf("\n");

    return 0;
}
