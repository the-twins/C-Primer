// pe12-2a.c
// comile with pe12-2b.c
#include <stdio.h>
#include <stdlib.h>
#include "pe12-2a.h"

#define KM 100

float distance = 0;
float fuel_com = 0;
int mode = 0;

void set_mode(int first_mode)
{
    extern int mode;
    if(first_mode > 1)
        printf("Invalid mode specified. Mode %d used.\n", mode);
      
    else
        mode = first_mode;

}

void get_info(void)
{
    extern float distance;
    extern float fuel_com;
    extern int mode;
    if(mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel_com);
    }
    if(mode == 1)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel_com);
    }
    if (mode == -1)
        exit(EXIT_FAILURE);
}

void show_info(void)
{
    extern float distance; 
    extern float fuel_com;
    extern int mode;
    if(mode == 0)
        printf("Fuel consumption is %.2f liters per %d km.\n", KM * fuel_com / distance, KM);
    if(mode == 1)
        printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel_com);
    if(mode == -1)
        exit(EXIT_FAILURE);
}
    
    
        
    
      
    
    
        
