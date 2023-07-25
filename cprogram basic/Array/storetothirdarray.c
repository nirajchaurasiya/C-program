#include <stdio.h>
#include <conio.h>
void main()
{
    int sum[5], arr1[5] = {1, 2, 3, 4, 5}, arr2[5] = {5, 6, 7, 8, 9};
    int add;
    for (int i = 0; i < 5; i++)
    {
        add = arr1[i] + arr2[i];
        sum[i] = add;
    }
    printf("New array is:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", sum[i]);
    }
}