// Write a program that opens and reads a text file and records how many times each word
// occurs in the file. Use a binary search tree modified to store both a word and the number
// of times it occurs. After the program has read the file, it should offer a menu with three
// choices. The first is to list all the words along with the number of occurrences. The
// second is to let you enter a word, with the program reporting how many times the word
// occurred in the file. The third choice is to quit.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include"../../11_strings/lib.h"

#define SLEN 30

typedef struct word_tree {
    char word[SLEN];
    unsigned int count;
    struct word_tree * left;
    struct word_tree * right;
} WordTree;

char menu(void);
void lowercase(char * str);
WordTree * add_word(WordTree * pt, char * word);
void print_tree(const WordTree * pt);
void findwords(const WordTree * pt);
int compar(const WordTree * pt, char * find_word);

int main(int argc, char * argv[])
{
    char temp[SLEN];
    FILE * fp;
    char choice;
    WordTree * tree = NULL;

    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp, "%s", temp) == 1)
    {
        lowercase(temp);
        if (tree == NULL)
            tree = add_word(tree, temp);
        else
            add_word(tree, temp);
        if(!tree)
        {
            fprintf(stderr, "Can't allocate memory.\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose(fp);

    while((choice = menu()) != 'q')
    {
        switch(choice)
        {
            case 's' :  print_tree(tree);
                break;
            case 'f' :  findwords(tree);
                break;
            case 'q' :  printf("Bye!\n");
                break;
            default  :  puts("Switching error");
        }
    }

    return 0;
}

char menu(void)
{
    int ch;

    puts("Enter the letter corresponding to your choice:");
    puts("s) Show list all the words along with the number of occurrences");
    puts("f) Enter a word and program reporting how many times the word occurred in the file");
    puts("q) Quit");
    while((ch = getchar()) != EOF)
    {
        while(getchar() != '\n')  // discard rest of line
            continue;
        ch = tolower(ch);
        if(strchr("sfq", ch) == NULL)
            puts("Please enter an s, f, or q:");
        else
            break;
    }
    if(ch == EOF)                 // make EOF cause program to quit
        ch = 'q';

    return ch;
}

WordTree * add_word(WordTree * pt, char * word)
{
    WordTree * node = NULL;
    if(pt == NULL)
    {
        node = (WordTree *) malloc(sizeof(WordTree));
        if(node == NULL)
            return NULL;
        strcpy(node->word, word);
        node->count = 1;
        pt = node;
        return node;
    }
    else if(strcmp(pt->word, word) == 0)
    {
        pt->count++;
        return pt;
    }
    else if(strcmp(pt->word, word) > 0)
    {
        node = add_word(pt->left, word);
        if(pt->left == NULL)
            pt->left = node;
        return node;
    }
    else
    {
        node = add_word(pt->right, word);
        if(pt->right == NULL)
            pt->right = node;
        return node;
    }
}

void lowercase(char * str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void print_tree(const WordTree * pt)
{
    if(pt != NULL)
    {
        print_tree(pt->left);
        printf("%s - %d times.\n", pt->word, pt->count);
        print_tree(pt->right);
    }
}

void findwords(const WordTree * pt)
{
    char find_word[SLEN];
    int find = 0;
    printf("Enter a word to search in the text:\n");
    s_gets(find_word, SLEN);
    if(pt != NULL)
        find = compar(pt, find_word);
    if(find == 0)
        printf("Word not found.\n");
    else
        printf("%s is in the text. %d repetitions in the text.\n", find_word, find);
}

int compar(const WordTree * pt, char * find_word)
{
   int count = 0;
   if(pt == NULL)
       return 0;
   if(strcmp(find_word, pt->word) == 0)
      return pt->count;
   count = compar(pt->left, find_word);
   if(count)
       return count;
   return compar(pt->right, find_word);
} 
