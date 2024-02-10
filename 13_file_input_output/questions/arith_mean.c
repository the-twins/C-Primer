// Write a program that takes zero command-line arguments or one command-line
// argument. If there is one argument, it is interpreted as the name of a file. If there is no
// argument, the standard input (stdin) is to be used for input. Assume that the input
// consists entirely of floating-point numbers. Have the program calculate and report the
// arithmetic mean (the average) of the input numbers.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * fp;
    double numb;
    double sum = 0.0;
    int count = 0;
    if(argc == 1)
    {
        fp = stdin;
        printf("Enter floating-point numbers to calculate the arithmetic mean:\n");
        printf("To complete, enter # at the beginning of the line.\n");
    }
    if(argc > 2)
        exit(EXIT_FAILURE);    
    else if(argc == 2)
        if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%lf", &numb) == 1)
    {
        sum += numb;
        count++;
    }
    printf("The arithmetic mean of the input numbers = %lf\n", sum / count);

    return 0;
}
