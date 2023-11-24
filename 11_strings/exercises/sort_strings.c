// Write a program that reads in up 10 strings or to EOF, whichever comes first. Have it
// offer the user a menu with five choices: print the original list of strings, print the strings
// in ASCII collating sequence, print the strings in order of increasing length, print the
// strings in order of the length of the first word in the string, and quit. Have the menu
// recycle until the user enters the quit request. The program, of couras, should actually
// perform the promised tasks.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../lib.c"

#define SIZE 100
#define LIM 10

void print(char input[][SIZE], int n);
void sort(char * pt[], int n);
void sort_length(char * pt[], int n);
void sort_word(char * pt[], int n);
int length(char * pt);

int main(void)
{
    char input[LIM][SIZE];
    char *pt[LIM];
    char ch;
    int ct = 0;

    printf("Input up to %d lines (EOF to quit):\n", LIM);
    while(ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] !='\0')
    {
        pt[ct] = input[ct];
        ct++;
    }
    printf("1) Print the original list of strings.\n");
    printf("2) Print the strings in ASCII collating sequence.\n");
    printf("3) Print the strings in order of increasing length.\n");
    printf("4) Print the strings in order of the length of the first word in the string.\n");
    printf("5) Quit.\n");
    printf("Enter a number.\n");
    while ((ch = getchar()) != '5')
    {
        if(ch == '1')
            print(input, ct);
	if(ch == '2')
            sort(pt, ct);
        if(ch == '3')
            sort_length(pt, ct);
        if(ch == '4')
            sort_word(pt, ct);
    }

    return 0;
}

void print(char input[][SIZE], int n)
{
    int i;	
    for(i = 0; i < n; i++)
        puts(input[i]);
}

void sort(char * pt[], int n)
{
    char * temp;
    int i, top, seek;
    for(top = 0; top < n - 1; top++)
        for(seek = top + 1; seek < n; seek++)
            if(strcmp(pt[top], pt[seek]) > 0)
            {
                temp = pt[top];
		pt[top] = pt[seek];
		pt[seek] = temp;
	    }
    for(i = 0; i < n; i++)
        puts(pt[i]);
}

void sort_length(char * pt[], int n)
{
    int i, top, seek;
    char * temp;
    for(top = 0; top < n - 1; top++)
        for(seek = top + 1; seek < n; seek++)
            if(strlen(pt[top]) > strlen(pt[seek]))
            {
                temp = pt[top];
                pt[top] = pt[seek];
                pt[seek] = temp;
            }
    for(i = 0; i < n; i++)
        puts(pt[i]);
}

void sort_word(char * pt[], int n)
{
    int i, top, seek;
    char * temp;
    for(top = 0; top < n - 1; top++)
        for(seek = top + 1; seek < n; seek++)
            if(length(pt[top]) > length(pt[seek]))
            {
                temp = pt[top];
                pt[top] = pt[seek];
                pt[seek] = temp;
            }
    for(i = 0; i < n; i++)
        puts(pt[i]);
}

int length(char * pt)
{
    int length = 0;
    while(!isspace(*pt) && *pt != '\0')
    {
        pt++;
        length++;
    }
    return length;
}    

