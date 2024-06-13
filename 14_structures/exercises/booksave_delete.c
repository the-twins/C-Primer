// Modify Listing 14.14 so that as each record is read from the file and shown to you, you
// are given the chance to delete the record or to modify its contents. If you delete the
// record, use the vacated array position for the next record to be read. To allow changing
// the existing contents, you'll need to use the "r+b" mode instead of the "a+b" mode, and
// you'll have to pay more attention to positioning the file pointer so that appended records
// don't overwrite existing records. It's simplest to make all changes in the data stored in
// program memory and then write the final set of information to the file. One approach to
// keeping track is to add a member to the book structure that indicates whether it is to be
// deleted.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main (void)
{
    struct book library[MAXBKS];
    int count = 0;
    int option = 0;
    FILE * pbooks;
    int size = sizeof(struct book);

    pbooks = fopen("book.dat", "r");
    if(pbooks)
    {
        rewind(pbooks);
        while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
        {
            if(count == 0)
                puts("Current contents of book.dat:");
            printf("%s by %s: $%.2f\n", library[count].title,
                   library[count].author, library[count].value);
            printf("Choose an option:\n1) Change string\n2) Delete string\n3) Continue\n");
            scanf("%d", &option);
            if(option == 1)
            {
                puts("Enter the book titles");
	        while(getchar() != '\n');
                s_gets(library[count].title, MAXTITL);
                puts("Enter the author");
                s_gets(library[count].author, MAXAUTL);
                puts("Enter the value");
                scanf("%f", &library[count].value);
                count++;
            }
            if(option == 2)
                continue;
            if(option == 3)
                count++;
        }
        fclose(pbooks);
    }

    if(count < MAXBKS)
    {
        puts("Please add new book titles.");
        puts("Press [enter] at the start of a line to stop.");
        while(getchar() !='\n');
        while(count < MAXBKS && s_gets(library[count].title, MAXTITL)
              && library[count].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[count].author, MAXAUTL);
            puts("Nou enter the value.");
            scanf("%f", &library[count].value);
            while(getchar() != '\n')
                continue;
            count++;
            if(count == MAXBKS)
            {
                puts("The book.dat file is full.");
                break;
            }
            puts("Now enter the titles or press[enter] to quit.");
        }
    }
    else
        puts("The book.dat file is full.");

    if((pbooks = fopen("book.dat", "w+")) == NULL)
    {
        fprintf(stderr,"Can't open file 'book.dat' fo write.\n");
        EXIT_FAILURE;
    }
    if(count > 0)
    {
        fwrite(library, size, count, pbooks);
        rewind(pbooks);
        puts("Here is the list of your books:");
        while(fread(library, size, 1, pbooks))
            printf("%s by %s: $%.2f\n", library[0].title, library[0].author,  
                   library[0].value);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
