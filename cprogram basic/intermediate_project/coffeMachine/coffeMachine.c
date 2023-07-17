/*
    Author: Niraj Chaurasiya
    Programmed Date: July 17, 2023
    Time took to build: Approximately 1 hour
    Description: This project, "COFFEE MACHINE", aims to mimic a real-world coffee machine that provides coffee automatically to its customers.
    Initially, this project seemed hard for me to build, but during the process of making, I realized it is one of the easiest projects I have ever made.
    This project consists of 5 options, which are divided into two types: coffee type and system setting.
    Firstly, the coffee type is further classified into three types: latte, cappuccino, and espresso.
    To order a cappuccino, latte, or espresso, the customer needs to enter the type of coffee in the console.
    The program checks if all the ingredients are available to make the coffee. If the ingredients are available, it asks the customer to enter the denomination of the notes (5 Rs note, 10 Rs note, and 20 Rs note).
    If the entered money is equal to or greater than the actual cost of the coffee, the coffee is ordered with the extra money.
    However, if there are not enough ingredients available, it prints the message "There are not enough ingredients available right now".
    If the ingredients are available but the entered money is less than the actual cost, it simply refunds the entered money back to the customer.
    On the other hand, the system setting includes generating a report of the ingredients, selling coffee, and turning off the machine.
    If the user enters "off", the machine will be deactivated. Similarly, if the user enters "report", it will show the current reports of the machine's status.
*/
/*
    Trademark: ™ Niraj Chaurasiya
    License: This project is licensed under the MIT License. See the LICENSE file for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void order_latte();
void order_cappuccino();
void order_espresso();
void report(int water, int milk, int coffee, int money);
void intro();
// initialize the initial Report
int water = 100, milk = 80, coffee = 200, money = 0;
// initialize the ingredients and cost of the latte
int latte_water = 50, latte_milk = 25, latte_coffee = 10, latte_cost = 200;
// initialize the ingredients and cost of the cappuccino
int cappuccino_water = 50, cappuccino_milk = 75, cappuccino_coffee = 20, cappuccino_cost = 250;
// initialize the ingredients and cost of the espresso
// Initialize 5 ruppee note, 10 ruppee note and 20 ruppee note
int note_5, note_10, note_20, total_note_amount, extra_money, served_user = 0;
int espresso_water = 60, espresso_milk = 0, espresso_coffee = 25, espresso_cost = 170;
int main()
{
    // initialize choice
    char choice[15];

    system("cls");
    printf("   ******    *******   ******** ******** ******** ********\n");
    printf("  **////**  **/////** /**///// /**///// /**///// /**//// \n");
    printf(" **    //  **     //**/**      /**      /**      /**      \n");
    printf("/**       /**      /**/******* /******* /******* /******* \n");
    printf("/**       /**      /**/**////  /**////  /**////  /**////  \n");
    printf("//**    **//**     ** /**      /**      /**      /**      \n");
    printf(" //******  //*******  /**      /**      /********/********\n");
    printf("  //////    ///////   //       //       //////// ////////  \n");
    printf("\nHello user!\n");
    printf("--------------------------------------------------------------------------------\n");
    while (strcmp(choice, "off") != 0)
    {
        intro();

        scanf("%s", choice);
        if ((strcmp(choice, "latte") != 0) && (strcmp(choice, "cappuccino") != 0) && (strcmp(choice, "espresso") != 0) && (strcmp(choice, "off") != 0) && (strcmp(choice, "report") != 0))
        {
            printf("Invalid choice. Please enter a valid option.\n");
        }
        if (strcmp(choice, "latte") == 0)
        {
            order_latte();
        }
        if (strcmp(choice, "cappuccino") == 0)
        {
            order_cappuccino();
        }

        if (strcmp(choice, "espresso") == 0)
        {
            order_espresso();
        }

        if (strcmp(choice, "report") == 0)
        {
            report(water, milk, coffee, money);
        }
    }
    printf("-----------------------------------------------------\n");
    printf("|     Coffee Machine turned off. Goodbye!            |\n");
    printf("-----------------------------------------------------\n");
    return 0;
}
void order_latte()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("Wait, for we are checking the ingredients if it is enough to make latte coffee for you.\n");
    if (latte_water < water && latte_coffee < coffee || latte_milk < milk)
    {
        // printf("There are enough ingredients available.\n");
        // to enter the amount of 5 rupppee note
        printf("Please enter the amount of 5 rupee note\n");
        scanf("%d", &note_5);
        // to enter the amount of 10 rupppee note\n
        printf("Please enter the amount of 10 rupee note\n");
        scanf("%d", &note_10);
        // to enter the amount of 20 rupppee note\n
        printf("Please enter the amount of 20 rupee note\n");
        scanf("%d", &note_20);
        total_note_amount = note_5 * 5 + note_10 * 10 + note_20 * 20;
        if (total_note_amount == latte_cost)
        {
            printf("Thanks for your patience.\n");
            printf("Here is your coffee.\n");
            money += latte_cost;
            water -= latte_water;
            coffee -= latte_coffee;
            milk -= latte_milk;
            served_user++;
        }
        else if (total_note_amount > latte_cost)
        {
            printf("Thanks for your patience.\n");
            extra_money = total_note_amount - latte_cost;
            printf("Here is your coffee and extra NRs %d money\n", extra_money);
            money += latte_cost;
            water -= latte_water;
            coffee -= latte_coffee;
            milk -= latte_milk;
            served_user++;
        }
        else
        {
            printf("Sorry! Thats not enough amount. Money refunded\n");
        }
    }
    else
    {
        printf("Sorry! Not enough ingredients available right now.\n");
    }
    printf("--------------------------------------------------------------------------------\n");
}

void order_cappuccino()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("Wait, for we are checking the ingredients if it is enough to make cappuccino coffee for you.\n");
    if (cappuccino_water < water && cappuccino_coffee < coffee || cappuccino_milk < milk)
    {
        // printf("There are enough ingredients available.\n");
        // to enter the amount of 5 rupppee note
        printf("Please enter the amount of 5 rupee note\n");
        scanf("%d", &note_5);
        // to enter the amount of 10 rupppee note\n
        printf("Please enter the amount of 10 rupee note\n");
        scanf("%d", &note_10);
        // to enter the amount of 20 rupppee note\n
        printf("Please enter the amount of 20 rupee note\n");
        scanf("%d", &note_20);
        total_note_amount = note_5 * 5 + note_10 * 10 + note_20 * 20;
        if (total_note_amount == cappuccino_cost)
        {
            printf("Thanks for your patience.\n");
            printf("Here is your coffee.\n");
            money += cappuccino_cost;
            water -= cappuccino_water;
            coffee -= cappuccino_coffee;
            milk -= cappuccino_milk;
            served_user++;
        }
        else if (total_note_amount > cappuccino_cost)
        {
            printf("Thanks for your patience.\n");
            extra_money = total_note_amount - cappuccino_cost;
            printf("Here is your coffee and extra NRs %d money\n", extra_money);
            money += cappuccino_cost;
            water -= cappuccino_water;
            coffee -= cappuccino_coffee;
            milk -= cappuccino_milk;
            served_user++;
        }
        else
        {
            printf("Sorry! Thats not enough amount. Money refunded\n");
        }
    }
    else
    {
        printf("Sorry! Not enough ingredients available right now.\n");
    }
    printf("--------------------------------------------------------------------------------\n");
}

void order_espresso()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("Wait, for we are checking the ingredients if it is enough to make espresso coffee for you.\n");
    if (espresso_water < water && espresso_coffee < coffee || espresso_milk < milk)
    {
        // printf("There are enough ingredients available.\n");
        // to enter the amount of 5 rupppee note
        printf("Please enter the amount of 5 rupee note\n");
        scanf("%d", &note_5);
        // to enter the amount of 10 rupppee note\n
        printf("Please enter the amount of 10 rupee note\n");
        scanf("%d", &note_10);
        // to enter the amount of 20 rupppee note\n
        printf("Please enter the amount of 20 rupee note\n");
        scanf("%d", &note_20);
        total_note_amount = note_5 * 5 + note_10 * 10 + note_20 * 20;
        if (total_note_amount == espresso_cost)
        {
            printf("Thanks for your patience.\n");
            printf("Here is your coffee.\n");
            money += espresso_cost;
            water -= espresso_water;
            coffee -= espresso_coffee;
            milk -= espresso_milk;
            served_user++;
        }
        else if (total_note_amount > espresso_cost)
        {
            printf("Thanks for your patience.\n");
            extra_money = total_note_amount - espresso_cost;
            printf("Here is your coffee and extra NRs %d money\n", extra_money);
            money += espresso_cost;
            water -= espresso_water;
            coffee -= espresso_coffee;
            milk -= espresso_milk;
            served_user++;
        }
        else
        {
            printf("Sorry! Thats not enough amount. Money refunded\n");
        }
    }
    else
    {
        printf("Sorry! Not enough ingredients available right now.\n");
    }
    printf("--------------------------------------------------------------------------------\n");
}
void report(int water, int milk, int coffee, int money)
{
    printf("--------------------------------------------------------------------------------\n");
    printf("Here is your report.\n");
    printf("Water = %d ml\n", water);
    printf("Milk = %d ml\n", milk);
    printf("Coffee = %d gm\n", coffee);
    printf("User served = %d\n", served_user);
    printf("Money = NRs %d\n", money);
    printf("--------------------------------------------------------------------------------\n");
}

void intro()
{
    printf("--------------------------------------------------------------------------------\n");

    printf("What would you like to have? (latte/cappuccino/espresso)\n");
    printf("Enter 'off' to turn off the machine or 'report' to show the report.\n");
}