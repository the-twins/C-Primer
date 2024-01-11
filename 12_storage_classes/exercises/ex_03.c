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
    int mode;
    float distance, fuel_com;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    set_mode(&mode);
    while(mode >= 0)
    {
	get_info(mode, &distance, &fuel_com);
	show_info(mode, distance, fuel_com);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
	set_mode(&mode);
     }
     printf("Done.\n");
     return 0;
}

void set_mode(int * mode)
{
    int n_mode;
    if(*mode >= 2)
    {
        printf("Invalid mode specified. Mode %d used.\n", n_mode);
        *mode = n_mode;
    }
    else
        n_mode = *mode;
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
