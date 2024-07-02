// Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
// its service to for flights daily (Flights 102, 311, 444, and 519). Expand the program to
// handle four flights. Have a top-level menu that offers a choice of flight and the option
// to quit. Selecting a paticular flight should then bring up a menu similar to that of
// exercise 8. However, one new item should be added: confirming a set assignment. Also,
// the quit choice should be replaced with the choice of exiting to the top-level menu. Each
// display should indicate which flight is currently being handled. Also, the seat assignment
// display should indicate the confirmation status.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 40
#define SEAT 12
#define CONFIRMED 2
#define BUSY 1
#define FREE 0
#define COL_DATA "colossus.data"
#define FLIGHT 4

struct colossus {
    int numb;
    int status;
    char f_name[MAX];
    char l_name[MAX];
};

void free_seat(struct colossus [][SEAT], int n);
void list_free_seat(struct colossus[][SEAT], int n);
char *s_gets(char * st, int n);
char menu (int n);
void booking(struct colossus [][SEAT], int i, int n);
void delete(struct colossus [][SEAT], int i, int n);
void confirm(struct colossus[][SEAT], int i, int n);
const int numb_flight[] = {102, 311, 444, 519};

int main(void)
{
    struct colossus seats[FLIGHT][SEAT];
    FILE * data;
    int flight;
    char ch;
    int i, j;
    int n = 0;
    int size = sizeof(struct colossus);

    data = fopen(COL_DATA, "rb");
    for(i = 0; i < FLIGHT; i++)
        for(j = 0; j < SEAT; j++)
        {
            seats[i][j].numb = j + 1;
            seats[i][j]. status = FREE;
            seats[i][j].f_name[0] = '\0';
            seats[i][j].l_name[0] = '\0';
        }
    if(data)
    {
        rewind(data);
        fread(seats, size * SEAT, FLIGHT, data);
        fclose(data);
    }
    printf("Choose a flight:\n");
    printf("0) 102            1) 311\n");
    printf("2) 444            3) 519\n");
    printf("4) EXIT\n");
    while(scanf("%d", &flight) && flight >= 0 && flight <= 3)
    {
        while(getchar() != '\n');
        while ((ch = menu(numb_flight[flight])) !='\n')
        {
            if( ch == 'a')
                free_seat(seats, flight);
            if( ch == 'b')
                list_free_seat(seats, flight);
            if( ch == 'c')
            {
                printf("Flight %d\n", numb_flight[flight]);
                printf("Seat number  '0' - free / '1' - buzy / '2' - confirmed   Passenger name\n");
                printf("-----------------------------------------------------------------------\n");
                for(i = 0; i < SEAT; i++)
                    printf("%d%19d                                          %s %s\n", 
                           seats[flight][i].numb, seats[flight][i].status, seats[flight][i].f_name, 
                           seats[flight][i].l_name);
            }
            if( ch == 'd')
            {
                printf("Enter seat number to booking on the flight %d:\n", numb_flight[flight]);
                if(scanf("%d", &n) && n > 0 && n <= SEAT)
                {
                    while(getchar() !='\n');
                    booking(seats, n, flight);
                }
                else
                {
                    while(getchar() !='\n');
                    printf("You entered seat number incorrectly.\n");
                }
            }
            if( ch == 'e')
            {
                printf("Enter seat number to delete on the flight %d:\n", numb_flight[flight]);
                if(scanf("%d", &n) && n > 0 && n <= SEAT)
                {
                    while(getchar() !='\n');
                    delete(seats, n, flight);
                }
                else
                {
                    while(getchar() !='\n');
                    printf("You entered seat number incorrectly.\n");
                }
            }
            if( ch == 'f')
            {
                printf("Enter seat number to confirm your reservation on the flight %d:\n",
                        numb_flight[flight]);
                if(scanf("%d", &n) && n > 0 && n <= SEAT)
                {
                    while(getchar() !='\n');
                    confirm(seats, n, flight);
                }
                else
                {
                    while(getchar() !='\n');
                    printf("You entered seat number incorrectly.\n");
                }
            }
            if( ch == 'g')
                break;
        }
        printf("Choose a flight:\n");
        printf("0) 102        1) 311\n");
        printf("2) 444        3) 519\n");
        printf("4) EXIT\n");
    }
    if((data = fopen(COL_DATA, "wb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s to write.\n", COL_DATA);
        exit(EXIT_FAILURE);
    }
    fwrite(seats, size * SEAT, FLIGHT, data);
    rewind(data);
    printf("Bye.\n");
    fclose(data);

    return 0;
}
               
char menu(int n)
{
    char i;
    printf("To choose a function, enter its letter label for the flight %d:\n", n);
    printf("a) Show number of empty seats.\n");
    printf("b) Show list of empty seats.\n");
    printf("c) Show alphabetical list of seats.\n");
    printf("d) Assign a customer to a seat assignment.\n");
    printf("e) Delete a seat assignment.\n");
    printf("f) Confirm reservation.\n");
    printf("g) Quit.\n");
    i = getchar();
    while(getchar() != '\n');

    return i;
}

void free_seat(struct colossus seats[][SEAT], int n)
{
    int free = 0;
    int j = 0;
    for(j = 0; j < SEAT; j++)
        if(seats[n][j].status == FREE)
            free++;
    printf("Number of empty seats on the flight %d is %d.\n", numb_flight[n], free);
}

void list_free_seat(struct colossus seats[][SEAT], int n)
{
    int j = 0;
    for(j = 0; j < SEAT; j++)
    {
        if(seats[n][j].status == FREE)
            printf("%d is free on the flight %d.\n", seats[n][j].numb, numb_flight[n]);
    }
}

void booking(struct colossus seats[][SEAT], int i, int n)
{
    int j = 0;
    char ans;
    if(seats[n][i-1].status == BUSY || seats[n][i - 1].status == CONFIRMED)
    {
        printf("It's busy. Choose another seat on the flight %d.\n", numb_flight[n]);
        return;
    }
    printf("Enter your first name:\n");
    s_gets(seats[n][i - 1].f_name, MAX);
    for(j = 0; j < MAX; j++)
        seats[n][i - 1].f_name[j] = toupper(seats[n][i - 1].f_name[j]);
    printf("Enter your last name:\n");
    s_gets(seats[n][i - 1].l_name, MAX);
    for(j = 0; j < MAX; j++)
        seats[n][i - 1].l_name[j] = toupper(seats[n][i - 1].l_name[j]);
    printf("Do you want to save your reservation on the flight %d? "
           "If yes press Y, if no press N:\n", numb_flight[n]);
    ans = getchar();
    if(ans == 'Y'|| ans == 'y')
    {
        seats[n][i - 1].status = BUSY;
        printf("%s %s, you have reserved seat number %d on the flight %d\n", seats[n][i-1].f_name, 
               seats[n][i-1].l_name, i, numb_flight[n]);
    }
    else
    {
        seats[n][i - 1].f_name[0] = '\0';
        seats[n][i - 1].l_name[0] = '\0';
    }
    while(getchar() !='\n');
}

void delete(struct colossus seats[][SEAT], int i, int n)
{
    char f_names[MAX];
    char l_names[MAX];
    int j = 0;
    char ans;
    printf("Enter your first name:\n");
    s_gets(f_names, MAX);
    for(j = 0; j < MAX; j++)
        f_names[j] = toupper(f_names[j]);
    printf("Enter your last name:\n");
    s_gets(l_names, MAX);
    for(j = 0; j < MAX; j++)
        l_names[j] = toupper(l_names[j]);
    printf("Do you want to delete your reservation on the flight %d? If yes press Y, if no press "
           "N:\n", numb_flight[n]);
    ans = getchar();
    if(ans == 'Y'|| ans == 'y')
    {
        if(strcmp(f_names, seats[n][i -1].f_name) == 0 && strcmp(l_names, seats[n][i - 1].l_name) 
           == 0)
        {
            seats[n][i - 1].f_name[0] = '\0';
            seats[n][i - 1].l_name[0] = '\0';
            seats[n][i - 1].status = FREE;
            printf("Your reservation on the flight %d has been deleted.\n", numb_flight[n]);
        }
        else
            printf("You entered the data incorrectly.\n");
    }
    while(getchar() !='\n');
}

void confirm(struct colossus seats[][SEAT], int i, int n)
{
    char ans;
    if(seats[n][i - 1].status == FREE)
    {
        printf("You must reserve this seat.\n");
        return;
    }
    printf("%s %s, would you like to confirm your reservation for %d seat on flight %d?\n",
           seats[n][i - 1].f_name, seats[n][i - 1].l_name, i, numb_flight[n]);
    printf("Enter Y to confirm or N to exit to the menu:\n");
    ans = getchar();
    if(ans == 'Y' || ans == 'y')
    {
        seats[n][i - 1].status = CONFIRMED;
        printf("%s %s, your reservation on flight %d is confirmed.\n", seats[n][i - 1].f_name,
               seats[n][i - 1].l_name, numb_flight[n]);
    }
    while(getchar() !='\n');
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
