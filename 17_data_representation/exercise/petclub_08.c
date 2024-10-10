// Modify the Pet Club program so that all pets with the same name are stored in
// the same node. When the user chooses to find a pet, the program should request the pet
// name and then list all pets(along with their kinds) having that name.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree_08.h"

#define SLEN 20

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item temp);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while((choice = menu()) != 'q')
    {
        switch(choice)
        {
            case 'a' :  addpet(&pets);
                break;
            case 'l' :  showpets(&pets);
                break;
            case 'f' :  findpet(&pets);
                break;
            case 'n' :  printf("%d pets in club\n",
                                TreeItemCount(&pets));
                break;
            case 'd' :  droppet(&pets);
                break;
            default  :  puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while((ch = getchar()) != EOF)
    {
        while(getchar() != '\n')  // discard rest of line
            continue;
        ch = tolower(ch);
        if(strchr("alfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if(ch == EOF)                 // make EOF cause program to quit
        ch = 'q';

    return ch;
}

void addpet(Tree * pt)
{
    Item temp;

    if(TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind[0], SLEN);
        temp.n = 1;
        uppercase(temp.petname);
        uppercase(temp.petkind[0]);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt)
{
    if(TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item temp)
{
    int i = 0;
    printf("Pet: %s Kind: ", temp.petname);
    for(i = 0; i < temp.n; i++)
        printf("%s ", temp.petkind[i]);
    printf("\n");
}

void findpet(const Tree * pt)
{
    Item temp;

    if(TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;         // quit function if tree is empty
    }
    else
    {
        puts("Please enter name of pet you wish to find:");
        s_gets(temp.petname, SLEN);
        uppercase(temp.petname);
        FindWord(pt, &temp);
    }
}

void droppet(Tree * pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;         // quit function if tree is empty
    }
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind[0], SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s the %s ", temp.petname, temp.petkind[0]);
    if(DeleteItem(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char * str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
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
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
