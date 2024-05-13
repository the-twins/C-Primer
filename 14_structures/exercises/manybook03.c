// Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in
// the order entered, then alphabetized by title, and then in order of increased value.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * s_gets(char * st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100       // maximum number of books 

struct book {            // set up book template
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;         // end of structure template
};

void strsrt(struct book * libtaty[], int n);
void srtvalue(struct book * library[], int n);

int main(void)
{
    struct book library[MAXBKS]; // array of book structures
    struct book * sort[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
          && library[count].title[0] != '\0')
    {
        sort[count] = &library[count];
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;          // clear input line
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
           library[index].author, library[index].value);
        printf("\nHere is the list of your books alphabetized by title:\n");
        strsrt(sort, count);
        printf("\nHere is the list of your books in order of increased value:\n");
        srtvalue(sort, count);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

char * s_gets(char *st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');  // look for newline
        if (find)                 // if the address is not NULL 
            *find = '\0';         // place a null character there
        else
            while (getchar() != '\n')
                continue;         // dispose of rest of line
    }
    return ret_val;
}

void strsrt(struct book * library[], int n)
{
    struct book * temp;
    int top, seek, i;
    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
           if (strcmp(library[top]->title, library[seek]->title) > 0)
           {
               temp = library[top];
               library[top] = library[seek];
               library[seek] = temp;
           }
    for (i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", library[i]->title, library[i]->author, library[i]->value);
}

void srtvalue(struct book * library[], int n)
{
    struct book * temp;
    int top, seek, i;
    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
            if (library[top]->value > library[seek]->value)
            {
                temp = library[top];
                library[top] = library[seek];
                library[seek] = temp;
            }
    for (i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", library[i]->title, library[i]->author, library[i]->value);
}
