#include <stdio.h>

int menu(int min, int max);
void print(void);

int main(void)
{
    int choice;
    while ((choice = menu(1,4)) != 4)
        printf("Your choice is %d. Try again.\n", choice);
    printf("Bye!\n");

    return 0;
}

int menu(int min, int max)
{
     int num;
     print();
     while (scanf("%d", &num) == 1)
     {
         if (num > max || num < min)
             print();
	 else
             return num;
     }
     return 4;
}

void print(void)
{
     printf("Please choose one of the following:\n");
     printf("1) copy files       2) move files\n");
     printf("3) remove files     4) quit\n");
     printf("Enter the number of your choice: \n");
}
