// typesize.c -- prints out type sizes
#include <stdio.h>

int main(void)
{
    // C99 provides a %zd specifier for size
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type short has a size of %zd bytes.\n", sizeof(short));
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n",
           sizeof(long long));
    printf("Type double has a size of %zd bytes.\n", sizeof(double));
    printf("Type long double has a size of %zd bytes.\n",
           sizeof(long double));

    return 0;
}
