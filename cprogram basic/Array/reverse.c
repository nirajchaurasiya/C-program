#include <stdio.h>
#include <conio.h>
void main()
{
    int a[5];
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Entered data are:\n");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d\t", a[i]);
    }
}