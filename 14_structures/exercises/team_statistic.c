// A text file holds information about a softball team. Each line has data arranged as
// follows:
// 4 Jessie Joybat 5 2 1 1
// The first item is the player's number, conveniently in the range 0-18. The second item
// is the player's first name, and the third is the player's last name. Each name is a single
// word. The next item is the player's official times at bat, followed by the number of hits,
// walks, and runs batted in (RBIs). The file may contain data for more than one game,
// so the same player may have more than one line of data, and there may be data for
// other players between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and last names, the
// at bats, hits, walks, and RBIs(runs batted in), and the batting average (to be calculated
// later). You can use the player number as an array index. The program should read to end-
// of-file, and it should keep cumulative totals for each player.
//
// The world of baseball statistics is an involved one. For example, a walk or reaching base
// on an error doesn't count as an at-bat but could possibly produce an RBI. But all this
// program has to do is read and process the data file, as described next, without worrying
// about how realistic the data is.
//
// The simplest way for the program to proceed is to initialize the structure contents to
// zeros, read the file data into temporary variables, and then add them to the contents of
// the corresponding structure. After the program has finished reading the file, it shoud
// then calculate the battingaverage for each player and store it in the corresponding
// structure member. The batting average is calculated by dividing the cumulative number
// of hits for a player by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each player along
// with a line showing the combined statistics for the entire team.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT "text.txt"
#define MAX 30
#define PLAYERS 19

struct team {
    char first[MAX];
    char last[MAX];
    int bat;
    int hit;
    int walk;
    int rbi;
    float batting_avrg;
};

int main(void)
{
    struct team people[PLAYERS] = {
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0},
        {"","",0,0,0,0,0.0}
    };
    FILE * data;
    int i = 0;
    char name_f[MAX];
    char name_l[MAX];
    int bt = 0;
    int wlk = 0;
    int ht = 0;
    int rb = 0;
    if((data = fopen(TEXT, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s file.\n", TEXT);
        EXIT_FAILURE;
    }
    while(fscanf(data, "%d %s %s %d %d %d %d", &i, name_f, name_l, &bt, &ht, &wlk, &rb) == 7)
    {
        strcpy(people[i].first, name_f);
	strcpy(people[i].last, name_l);
	people[i].bat += bt;
        people[i].hit += ht;
        people[i].walk += wlk;
        people[i].rbi += rb;
    }
    for(i = 0; i < PLAYERS; i++)
        printf("%s %s. At bats - %d Hits - %d Walks - %d RBIs - %d Batting average - %.2f\n",
               people[i].first, people[i].last, people[i].bat, people[i].hit, people[i].walk,
               people[i].rbi, (float)people[i].hit / (float)people[i].bat);

    return 0;
}
