// Write a program with the following behavior. First, it asks you how many words you
// wish to enter. Then it has you enter the words, and then it displays the words. Use
// malloc() and answer to the first question (the number of words) to create a dynamic
// array of corresponding number of pointer-to-char.(Note that because each element
// in the array is a pointer-to-char, the pointer used to store the return value of malloc()
// should be a pointer-to-a-pointer-to-char.) When reading the string, the program should
// read the word info a temporary array of char, use malloc() to allocate enough storage
// to hold the word, and store the address in the array of char pointers. Then it should
// copy the word from the temporary array into the allocated storage. Thus, you wind up
// with an array of character pointers, each pointing to an object of the precise size needed
// to store the paticular word. A sample run could look like this:
// How many words do you wish to enter? 5
// Enter 5 words now:
// I enjoyed doing the exercise
// Here are your words:
// I
// enjoyed
// doing
// this
// exercise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

int main(void)
{
    int n, i, j;
    char ** pcl;
    char * word;
    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    printf("Enter %d words now: \n", n);
    pcl = (char **) malloc(n * sizeof(char *));
    for(i = 0; i < n; i++)
    {
	word = (char *) malloc(MAX * sizeof(char));
        scanf("%s", word);
        pcl[i] = word;
    }
    printf("Here are your words:\n");
    for (j = 0; j < n; j++)
        printf("%s\n", *(pcl + j));
    free(pcl);

    return 0;
}
