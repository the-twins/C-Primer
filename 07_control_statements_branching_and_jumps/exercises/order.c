// The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for 
// $1.15 per pound, and carrots for $1.09 per pound. It gives a 5% discount 
// for orders of $100 or more prior to adding shipping costs. It charges $6.50 
// shipping and handling for any order of 5 pounds or under, $14.00 shipping 
// and handling for orders over 5 pounds and under 20 pounds, and $14.00 plus 
// $0.50 per pound for shipments of 20 pounds or more. Write a program that 
// uses a switch statement in a loop such that a response of a lets the user 
// enter the pounds of artichokes desired, b the pounds of beets, c the pounds 
// of carrots, and q allows the user to exit the ordering process. The program 
// should keep track of cumulative totals. That is, if the user enters 4 pounds 
// of beets and later enters 5 pounds of beets, the program should use report 
// 9 pounds of beets. The program then should compute the total charges, the 
// discount, if any, the shipping charges, and the grand total. The program 
// then should display all the purchase information: the cost per pound, the 
// pounds ordered, and the cost for that order for each vegetable, the total 
// cost of the order, the discount (if there is one), the shipping charge, and 
// the grand total of all the charges.
#include <stdio.h>

#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT 0.05
#define OVER 100
#define RATE1 6.5
#define RATE2 14.0
#define RATE3 0.5
#define BREAK1 5
#define BREAK2 20
#define MIN_PRICE 0.01

int main (void)
{
    float pound;
    float cost_a = 0;
    float cost_b = 0;
    float cost_c = 0;
    float pound_a = 0;
    float pound_b = 0;
    float pound_c = 0;
    float discount = 0;
    float all_cost;
    float all_pound;
    float delivery;
    char category;

    printf("Choose your category to enter the pounds (q to quit):\n");
    printf("a) Artichoke $2.05\n");
    printf("b) Beet      $1.15\n");
    printf("c) Carrot    $1.09\n");  
    while ((category = getchar()) != 'q')
    {
        switch (category)
        {
            case 'a' : printf("Enter weight in pounds:\n");
                       scanf("%f", &pound);
                       pound_a += pound;
                       cost_a = pound_a * ARTICHOKE;
                       break;
            case 'b' : printf("Enter weight in pounds:\n");
                       scanf("%f", &pound);
                       pound_b += pound;
                       cost_b = pound_b * BEET;
                       break;
            case 'c' : printf("Enter weight in pounds:\n");
                       scanf("%f", &pound);
                       pound_c += pound;
                       cost_c = pound_c * CARROT;
                       break;
            default :  printf("Choose the number of your category or quit:\n");
                       continue;
        }
    }
    all_cost = cost_a + cost_b + cost_c;
    all_pound = pound_a + pound_b + pound_c;
    if (all_cost <= MIN_PRICE)
    {
        printf("Order is cancelled. Bye!\n");
	return 0;
    }
    if (all_cost >= OVER)
        discount = all_cost * DISCOUNT;
    if (all_pound < BREAK1)
        delivery = RATE1;
    else if (all_pound <= BREAK2)
        delivery = RATE2;
    else if (all_pound > BREAK2)
        delivery = RATE2 + (all_pound - BREAK2) * RATE3;
    
    printf("Item        Amount      Price      Total\n");
    printf("---------------------------------------------\n");
    printf("Artichokes  %-10.2f  $%.2f      $%.2f\n", pound_a, ARTICHOKE, cost_a);
    printf("Beets       %-10.2f  $%.2f      $%.2f\n", pound_b, BEET, cost_b);
    printf("Carrots     %-10.2f  $%.2f      $%.2f\n", pound_c, CARROT, cost_c);
    printf("---------------------------------------------\n");
    printf("            %-15.2f        $%.2f\n", all_pound, all_cost);
    printf("*********************************************\n");
    printf("                         Discount: $%.2f\n", discount);
    printf("              Total with discount: $%.2f\n", all_cost - discount);
    printf("---------------------------------------------\n");
    printf("                         Shipment: $%.2f\n", delivery);
    printf("                      Grand total: $%.2f\n", all_cost + delivery - discount);

    return 0;
}
