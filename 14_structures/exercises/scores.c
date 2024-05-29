// Write a program that fits the following recipe:
//  a. Externally define a name structure template with two members: a string to hold the
//     first name and a string to hold the second name.
//  b. Externally define a student structure template with three members: a name
//     structure , a grade array to hold three floating-point scores, and a variable to hold
//     the average of those scores.
//  c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
//     structures and initialize the name portions to name of your choice. Use functions
//     to perform the tasks described in parts d., e., f., and g.
//  d. Interactively acquire scores for each student. Place the scores in the grade
//     array portion of the appropriate structure. The required looping can be done 
//     in main() or in the function, as you prefer.
//  e. Calculate the average score value for each structure and assign it to the proper
//     member.
//  f. Print the information in each structure.
//  g. Print the class average for each of the numeric structure members.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CSIZE 4
#define MAX 30
#define SCORE 3

struct name {
    char first[MAX];
    char last[MAX];
};
struct student {
    struct name names;
    float grade[SCORE];
    float average_scr;
};
int ent_scores(struct student scores[], char * f, char * l);
void aver_scr(struct student * scores);
void print_struct(struct student []);

int main(void)
{
    struct student scores[CSIZE] = {
        {{"IVAN","IVANOV"}, {0,0,0}, 0},
        {{"MARY", "STAR"}, {0,0,0}, 0},
        {{"SARA", "RUSOVA"}, {0,0,0}, 0},
        {{"TARAS", "VODA"}, {0,0,0}, 0}
    };
    char f_name[MAX];
    char l_name[MAX];
    int i, j;
    printf("Enter student first name (EOF to quit):\n");
    while(scanf("%s", f_name) != EOF)
    {
        printf("Enter student last name:\n");
        scanf("%s", l_name);
        for(j = 0; j < MAX; j++)
        {
            f_name[j] = toupper(f_name[j]);
            l_name[j] = toupper(l_name[j]);
        }
        ent_scores(scores, f_name, l_name);
        aver_scr(&scores[i]);
        printf("Enter student first name(EOF to quit):\n");
    }
    print_struct(scores);
    return 0;
}

int ent_scores(struct student scores[], char * f, char * l)
{
    int i;
    for(i = 0; i < CSIZE; i++)
    {
        if((strcmp(f, scores[i].names.first) == 0) && (strcmp(l, scores[i].names.last) == 0))
        {
            printf("Enter scores:\n");
            scanf("%f %f %f", &scores[i].grade[0], &scores[i].grade[1], &scores[i].grade[2]);
            return i;
        }
        else
        {
            printf("You entered name student's incorrectly.\n");
            return 1;
        }
    }
}

void aver_scr(struct student * scores)
{
    float sum;
    sum = (scores->grade[0] + scores->grade[1] + scores->grade[2]) / SCORE;
    scores->average_scr = sum;
}

void print_struct(struct student scores[])
{
    int i;
    for( i = 0; i < CSIZE; i++)
        printf("%s %s -- %.2f, %.2f, %.2f. Average rating = %.2f\n", scores[i].names.first,
               scores[i].names.last, scores[i].grade[0], scores[i].grade[1], scores[i].grade[2],
               scores[i].average_scr);
}
