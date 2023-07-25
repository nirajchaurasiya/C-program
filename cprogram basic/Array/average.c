#include <stdio.h>
#include <conio.h>
void main()
{
    int a[5];
    int avg = 0;
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        avg += a[i];
    }
    printf("Average of entered number is %d", avg / 5);
}