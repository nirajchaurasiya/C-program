/*
    datat_type variable_name[data_size];
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10];
    for (int i = 0; i < 4; i++)
    {
        printf("Enter %d number\n", i + 1);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("The number is %d\t", a[i]);
    }
}