// Redesign the program described in Programming Exercise 2 so that it uses only automatic
// variables. Have the program offer the same user interface - that is, it should prompt the
// user to entrer a mode, and so on. You'll have to come up with a different set of function
// calls, however.
#include <stdio.h>
#include <stdlib.h>

#define KM 100
void set_mode (int * mode);
void get_info(int mode, float * distance, float * fuel_com);
void show_info(int mode, float distance, float fuel_com);

int main(void)
{
    int mode = 0;
    float distance, fuel_com;
    set_mode(&mode);
    while(mode >= 0)
    {
	get_info(mode, &distance, &fuel_com);
	show_info(mode, distance, fuel_com);
	set_mode(&mode);
     }
     printf("Done.\n");
     return 0;
}

void set_mode(int * mode)
{
    printf("Enter 0 for metric mode, 1 for US mode. (-1 to quit): ");
    int new_mode;
    scanf("%d", &new_mode);
    if (new_mode > 1)
        printf("Invalid mode specified. Mode %d used.\n", *mode);
    else
	*mode = new_mode;
}

void get_info(int mode, float * distance, float * fuel_com)
{
    if(mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%f", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", fuel_com);
    }
    if(mode == 1)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", fuel_com);
    }
}

void show_info(int mode, float distance, float fuel_com)
{
    if(mode == 0)
        printf("Fuel consumption is %.2f liters per %d km.\n", KM * fuel_com / distance, KM);
    if(mode == 1)
        printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel_com);
}
