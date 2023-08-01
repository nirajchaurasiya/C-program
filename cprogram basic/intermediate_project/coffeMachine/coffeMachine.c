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
    Trademark: ™ Niraj Chaurasiya
    License: This project is licensed under the MIT License. See the LICENSE file for more details.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
void order_latte();
void order_cappuccino();
void order_espresso();
void reFill_ingredients();
void report(int water, int milk, int coffee, int money);
void intro();
void main_intro();
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

// Initialize the name
char user_name[30];
char lower_username[30];
char file_name[30];
char buffer[100];
char last_order[100];
// Initialize FILE
FILE *fp;
int main()
{
    // initialize choice
    char choice[15];

    main_intro();
    scanf("%s", user_name);

    for (int i = 0; i < strlen(user_name); i++)
    {
        lower_username[i] = tolower(user_name[i]);
    }
    lower_username[strlen(user_name)] = '\0'; // Add null-terminator at the end

    if (strcmp(lower_username, "") != 0)
    {
        sprintf(file_name, "%s.txt", lower_username);

        if (access(file_name, F_OK) != -1)
        {
            fp = fopen(file_name, "r");
            while (fgets(buffer, sizeof(buffer), fp) != NULL)
            {
                strcpy(last_order, buffer); // Copy the current line to last_order
            }
            fclose(fp);

            if (strlen(last_order) > 0)
            {
                printf("Hello, %s\n", user_name);
                printf("Welcome back!\n");
                printf("You ordered last time: %s", last_order);
                printf("What do you want today?\n");
            }
            else
            {
                printf("Hello, %s\n", user_name);
                printf("Welcome back!\n");
                printf("You didn't order anything last time.\n");
                printf("What do you want today?\n");
            }
        }
        else
        {
            fp = fopen(file_name, "w");
            if (fp != NULL)
            {
                printf("Hey, you are new to this machine\n");
                printf("Okay, I will save your name, so that next time you come, I can show you the recommendations.\n");
            }
            else
            {
                printf("Error opening the file.\n");
            }
        }
    }
    else
    {
        printf("User name can't be empty.\n");
    }

    while (strcmp(choice, "off") != 0)
    {
        intro();

        scanf("%s", choice);
        if ((strcmp(choice, "latte") != 0) && (strcmp(choice, "cappuccino") != 0) && (strcmp(choice, "espresso") != 0) && (strcmp(choice, "off") != 0) && (strcmp(choice, "report") != 0) && (strcmp(choice, "refill") != 0))
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
        if (strcmp(choice, "refill") == 0)
        {
            reFill_ingredients();
        }
    }
    printf("-----------------------------------------------------\n");
    printf("|     Coffee Machine turned off. Goodbye!            |\n");
    printf("-----------------------------------------------------\n");
    fclose(fp);
    return 0;
}

void main_intro()
{
    Beep(750, 800);
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

    printf("Enter your name: ");
}

void order_latte()
{
    fp = fopen(file_name, "a+");

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
            Beep(2000, 1800);
            MessageBox(NULL, "Here is your coffee", "Coffee Time", MB_OK);
            printf("Here is your coffee.\n");
            money += latte_cost;
            water -= latte_water;
            coffee -= latte_coffee;
            milk -= latte_milk;
            served_user++;
            if (fp != NULL)
            {
                fputs("Latte\n", fp);
                fclose(fp);
            }
            else
            {
                printf("Error opening the file.\n");
            }
        }
        else if (total_note_amount > latte_cost)
        {
            printf("Thanks for your patience.\n");
            Beep(2000, 1800);
            MessageBox(NULL, "Here is your coffee", "Coffee Time", MB_OK);
            extra_money = total_note_amount - latte_cost;
            printf("Here is your coffee and extra NRs %d money\n", extra_money);
            money += latte_cost;
            water -= latte_water;
            coffee -= latte_coffee;
            milk -= latte_milk;
            served_user++;
            if (fp != NULL)
            {
                fputs("Latte\n", fp);
                fclose(fp);
            }
            else
            {
                printf("Error opening the file.\n");
            }
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
    fp = fopen(file_name, "a+");
    if (fp != NULL)
    {
        fputs("Cappuccino\n", fp);
        fclose(fp);
    }
    else
    {
        printf("Error opening the file.\n");
    }
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
            Beep(2000, 1800);
            printf("Here is your coffee.\n");
            money += cappuccino_cost;
            water -= cappuccino_water;
            coffee -= cappuccino_coffee;
            milk -= cappuccino_milk;
            served_user++;
            if (fp != NULL)
            {
                fputs("Latte\n", fp);
                fclose(fp);
            }
            else
            {
                printf("Error opening the file.\n");
            }
        }
        else if (total_note_amount > cappuccino_cost)
        {
            printf("Thanks for your patience.\n");
            Beep(2000, 1800);
            extra_money = total_note_amount - cappuccino_cost;
            printf("Here is your coffee and extra NRs %d money\n", extra_money);
            money += cappuccino_cost;
            water -= cappuccino_water;
            coffee -= cappuccino_coffee;
            milk -= cappuccino_milk;
            served_user++;
            if (fp != NULL)
            {
                fputs("Latte\n", fp);
                fclose(fp);
            }
            else
            {
                printf("Error opening the file.\n");
            }
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
    fp = fopen(file_name, "a+");
    if (fp != NULL)
    {
        fputs("Espresso\n", fp);
        fclose(fp);
    }
    else
    {
        printf("Error opening the file.\n");
    }
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
            Beep(2000, 1800);
            printf("Here is your coffee.\n");
            money += espresso_cost;
            water -= espresso_water;
            coffee -= espresso_coffee;
            milk -= espresso_milk;
            served_user++;
            if (fp != NULL)
            {
                fputs("Latte\n", fp);
                fclose(fp);
            }
            else
            {
                printf("Error opening the file.\n");
            }
        }
        else if (total_note_amount > espresso_cost)
        {
            printf("Thanks for your patience.\n");
            Beep(2000, 1800);
            extra_money = total_note_amount - espresso_cost;
            printf("Here is your coffee and extra NRs %d money\n", extra_money);
            money += espresso_cost;
            water -= espresso_water;
            coffee -= espresso_coffee;
            milk -= espresso_milk;
            served_user++;
            if (fp != NULL)
            {
                fputs("Latte\n", fp);
                fclose(fp);
            }
            else
            {
                printf("Error opening the file.\n");
            }
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
    printf("Money earned = NRs %d\n", money);
    printf("--------------------------------------------------------------------------------\n");
}

void intro()
{
    printf("--------------------------------------------------------------------------------\n");

    printf("What would you like to have? (latte/cappuccino/espresso)\n");
    printf("Enter 'off' to turn off the machine or 'report' to show the report or 'refill' to reFill the ingredients.\n");
}
void reFill_ingredients()
{
    // printf("%s", file_name);
    // printf("%s", user_name);
    // printf("%s", lower_username);
    int num;
    int refill_amount;
    printf("--------------------------------------------------------------------------------\n");
    printf("Current status:\n");
    printf("Water = %d\n", water);
    printf("Milk = %d\n", milk);
    printf("Coffee = %d\n", coffee);
    printf("How many ingredients you want to refill? You have 3 options i.e. (water, milk, coffee) to fill\n");
    scanf("%d", &num);
    char ingre[10];
    int count = 0;
    if (num > 1 && num != '\0')
    {
        printf("Let! Refill the ingredients from beginning.\n");

        while (strcmp(ingre, "exit") != 0 || count == num)
        {
            for (int i = 0; i < num; i++)
            {
                printf("Choose one ingredient name from (milk, water, coffee) or enter exit to exit the refill mode\n");
                scanf("%s", &ingre);
                if ((strcmp(ingre, "water") == 0))
                {
                    printf("Enter the refill amount for %s\n", ingre);
                    scanf("%d", &refill_amount);
                    water += refill_amount;
                    printf("%s refilled success\n", ingre);
                    count++;
                }
                else if ((strcmp(ingre, "milk") == 0))
                {
                    printf("Enter the refill amount for %s\n", ingre);
                    scanf("%d", &refill_amount);
                    milk += refill_amount;
                    printf("%s refilled success\n", ingre);
                    count++;
                }
                else if ((strcmp(ingre, "coffee") == 0))
                {
                    printf("Enter the refill amount for %s\n", ingre);
                    scanf("%d", &refill_amount);
                    coffee += refill_amount;
                    printf("%s refilled success\n", ingre);
                    count++;
                }
                else if (strcmp(ingre, "exit") != 0)
                {
                    printf("Please enter the valid option from water, milk, and coffee.\n");
                }
                break;
            }
        }
    }
    else if (num == 1 && num != '\0')
    {
        printf("Choose one ingredient name from (milk, water, coffee)\n");
        scanf("%s", &ingre);
        if ((strcmp(ingre, "water") == 0))
        {
            printf("Enter the refill amount for %s\n", ingre);
            scanf("%d", &refill_amount);
            water += refill_amount;
            printf("%s refilled success\n", ingre);
        }
        else if ((strcmp(ingre, "milk") == 0))
        {
            printf("Enter the refill amount for %s\n", ingre);
            scanf("%d", &refill_amount);
            milk += refill_amount;
            printf("%s refilled success\n", ingre);
        }
        else if ((strcmp(ingre, "coffee") == 0))
        {
            printf("Enter the refill amount for %s\n", ingre);
            scanf("%d", &refill_amount);
            coffee += refill_amount;
            printf("%s refilled success\n", ingre);
        }
        else
        {
            printf("Please enter the valid option from water, milk, and coffee.\n");
        }
    }
    if (num == 0 && num != '\0')
    {
        printf("Okay! Refill later\n");
    }
    if (num == '\0')
    {
        printf("Please enter in number; eg: 1,2,3\n");
    }
}