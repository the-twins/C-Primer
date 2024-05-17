// Write a program that creates a structure template with two members according to the
// following criteria:
// a. The first member is social security number. The second member is a structure whith
// three members. Its first member contains a first name, its second member contains a
// middle name, and its final member contains a last name. Create and initialize an array
// of five such structures. Have the program print the data in this format:
// Dribble, Flossie M. - 302039823
// Only the initial letter of the middle name is printed, and a period is added. Neither the
// initial (of course) nor the period should be printed if the middle name member is empty.
// Write a function to do the printing; pass the structure array to the function.
// b. Modify part a. by passing the structure value instead of the address.
#include <stdio.h>

#define MAX 30
#define ALL 5

struct names {
    char first[MAX];
    char middle[MAX];
    char last[MAX];
};

struct people {
    unsigned long int numb;
    struct names three;
};

void print_struct(struct people *);
void print_struct_b(struct people pr); 

int main(void)
{
    int i;
    struct people date[ALL] = {
        {302039824,{"Lilia", "Ivanovna", "Karp"}},
        {302039825,{"Ivan", "Olegovich", "Shpak"}},
        {305689756,{"Iva", "Leonidovna", "Zhukova"}},
        {457899058,{"Alexey", "", "Fedorov"}},
        {355667643,{"Kirill", "Fedorovich", "Grinev"}}
    };
    for(i = 0; i < ALL; i++)
        print_struct(&date[i]);
    printf("\n");
    for(i = 0; i < ALL; i++)
        print_struct_b(date[i]);

    return 0;
}

void print_struct(struct people * pr)
{
    if(pr->three.middle[0] != '\0')
        printf("%s, %s %c. -- %lu\n",pr->three.last, pr->three.first, pr->three.middle[0], pr->numb);
    else
        printf("%s, %s -- %lu\n", pr->three.last, pr->three.first, pr->numb);
}

void print_struct_b(struct people pr)
{
 
    if(pr.three.middle[0] != '\0')
        printf("%s, %s %c. -- %lu"
               "\n", pr.three.last, pr.three.first, pr.three.middle[0], pr.numb);
    else
        printf("%s, %s -- %lu\n", pr.three.last, pr.three.last, pr.numb);
}
