#include <stdio.h>
#include <string.h>
#include <conio.h>
void main()
{
    char name;
top:
    printf("Enter between caffee as c/ tea as t/ water as w :\n");
    scanf("%c", &name);
    printf("----------------------------------------------------\n");
    switch (name)
    {
    case 'c':
        printf("Coffee\n");
        break;
    case 't':
        printf("Tea\n");
        break;
    case 'w':
        printf("water\n");
        break;
    default:
        printf("Default\n");
        break;
    }
    printf("----------------------------------------------------\n");
    goto top;
}