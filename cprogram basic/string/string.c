#include <stdio.h>
#include <conio.h>
void main()
{
    char name[30];
    printf("Enter your name:\n");
    scanf("%[^\n]", &name);
    printf("Entered name is %s", name);
}