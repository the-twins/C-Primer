// The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
// one flight daily. Write a seating reservation program with the following features:
//   a. The program uses an array of 12 structures. Each structure should hold a seat
//      identification number, a marker that indicates whether the seat is assigned, the last
//      name of the seat holder, and the first name of the seat holder.
//   b. The program displays the following menu:
//      To choose a function, enter its letter label:
//      a) Show number of empty seats
//      b) Show list of empty seats
//      c) Show alphabetical list of seats
//      d) Assign a customer to a seat assigment
//      e) Delete a seat assigment
//      f) Quit
//   c. The program successfully executes the promises of its menu. Choices d) and e)
//      require additional input, and each should enable the user to abort an entry.
//   d. After executing a particular function, the program shows the menu again, except
//      for choice f).
//   e. Data is saved in a file between runs. When the program is restarted, it first loads in
//      the data, if any, from the file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 40
#define SEAT 12
#define BUSY 1
#define FREE 0
#define COL_DATA "colossus.data"

struct colossus {
    int numb;
    int status;
    char f_name[MAX];
    char l_name[MAX];
};

void free_seat(struct colossus [], int n);
void list_free_seat(struct colossus[], int n);
char *s_gets(char * st, int n);
char menu (void);
void booking(struct colossus [], int n);
void delete(struct colossus [], int n);

int main(void)
{
    struct colossus seats[SEAT] = {
        {1, FREE, "",""},
        {2, FREE, "",""},
        {3, FREE, "",""},
        {4, FREE, "",""},
        {5, FREE, "",""},
        {6, FREE, "",""},
        {7, FREE, "",""},
        {8, FREE, "",""},
        {9, FREE, "",""},
        {10,FREE, "",""},
        {11,FREE, "",""},
        {12,FREE, "",""},
    };
    FILE * data;
    char ch;
    int i;
    int n = 0;
    int size = sizeof(struct colossus);

    data = fopen(COL_DATA, "rb");
    if(data)
    {
        rewind(data);
        fread(seats, size * SEAT, 1, data);
        fclose(data);
    }
    printf("MENU\n");
    while ((ch = menu()) !='\n' && ch != 'f')
    {
        if( ch == 'a')
            free_seat(seats, SEAT);
        if( ch == 'b')
            list_free_seat(seats, SEAT);
        if( ch == 'c')
        {
            printf("Seat number       '0' - free / '1' - buzy    Passenger name\n");
            printf("--------------------------------------------------------------\n");
            for(i = 0; i < SEAT; i++)
                printf("%d%19d                          %s %s\n", seats[i].numb,
                        seats[i].status, seats[i].f_name, seats[i].l_name);
        }
        if( ch == 'd')
        {
            printf("Enter seat number to booking:\n");
            if(scanf("%d", &n) && n > 0 && n <= SEAT)
                booking(seats, n);
            else
                printf("You entered seat number incorrectly.\n");
        }
        if( ch == 'e')
        {
            printf("Enter seat number to delete:\n");
            if(scanf("%d", &n) && n > 0 && n <= SEAT)
                delete(seats, n);
            else
                printf("You entered seat number incorrectly.\n");
        }
        if( ch == 'f')
            break;
        while(getchar() !='\n');
    }

    if((data = fopen(COL_DATA, "wb")) == NULL)
    {
        fprintf(stderr, "Can't open file COL_DATA to write.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(seats, size * SEAT, 1, data);
    rewind(data);
    printf("Bye.\n");
    fclose(data);

    return 0;
}
               
char menu(void)
{
    char i;
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats.\n");
    printf("b) Show list of empty seats.\n");
    printf("c) Show alphabetical list of seats.\n");
    printf("d) Assign a customer to a seat assignment.\n");
    printf("e) Delete a seat assignment.\n");
    printf("f) Quit.\n");
    i = getchar();

    return i;
}

void free_seat(struct colossus seats[], int i)
{
    int free = 0;
    int j = 0;
    for(j = 0; j < i; j++)
        if(seats[j].status == FREE)
            free++;
    printf("Number of empty seats is %d.\n", free);
}

void list_free_seat(struct colossus seats[], int i)
{
    int j = 0;
    for(j = 0; j < i; j++)
    {
        if(seats[j].status == FREE)
            printf("%d is free.\n", seats[j].numb);
    }
}

void booking(struct colossus seats[], int i)
{
    int j = 0;
    char ans;
    if(seats[i-1].status == BUSY)
    {
        printf("It's busy. Choose another seat.\n");
        return;
    }
    while(getchar() !='\n');
    printf("Enter your first name:\n");
    s_gets(seats[i - 1].f_name, MAX);
    for(j = 0; j < MAX; j++)
        seats[i - 1].f_name[j] = toupper(seats[i - 1].f_name[j]);
    printf("Enter your last name:\n");
    s_gets(seats[i - 1].l_name, MAX);
    for(j = 0; j < MAX; j++)
        seats[i - 1].l_name[j] = toupper(seats[i - 1].l_name[j]);
    printf("Do you want to save your reservation? If yes press Y, if no press N:\n");
    ans = getchar();
    if(ans == 'Y'|| ans == 'y')
    {
        seats[i - 1].status = BUSY;
        printf("%s %s, you have reserved seat number %d\n", seats[i-1].f_name, seats[i-1].l_name, 
                i);
    }
    else
    {
        seats[i - 1].f_name[0] = '\0';
        seats[i - 1].l_name[0] = '\0';
    }
}

void delete(struct colossus seats[], int i)
{
    char f_names[MAX];
    char l_names[MAX];
    int j = 0;
    char ans;
    printf("Enter your first name:\n");
    while(getchar() !='\n');
    s_gets(f_names, MAX);
    for(j = 0; j < MAX; j++)
        f_names[j] = toupper(f_names[j]);
    printf("Enter your last name:\n");
    s_gets(l_names, MAX);
    for(j = 0; j < MAX; j++)
        l_names[j] = toupper(l_names[j]);
    printf("Do you want to delete your reservation? If yes press Y, if no press N:\n");
    ans = getchar();
    if(ans == 'Y'|| ans == 'y')
    {
        if(strcmp(f_names, seats[i -1].f_name) == 0 && strcmp(l_names, seats[i - 1].l_name) == 0)
        {
            seats[i - 1].f_name[0] = '\0';
            seats[i - 1].l_name[0] = '\0';
            seats[i - 1].status = FREE;
            printf("Your reservation has been deleted.\n");
        }
        else
            printf("You entered the data incorrectly.\n");
    }
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
            while(getchar() !='\n')
                continue;
    }
    return ret_val;
}
