// Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user's
// response instead of using command-line arguments.
#include <stdio.h>
#include <stdlib.h>

#define MAX 41

int main(void)
{
    int ch;
    char name[MAX];
    FILE * fp;
    unsigned long count = 0;
    printf("Enter the name of file to be processed:\n");
    scanf("%s", name);
    if((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", name, count);

    return 0;
}
