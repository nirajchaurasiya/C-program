#include <stdio.h>
#include <conio.h>
void main()
{
    int a[2][3], i, j, sum = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", a[i][j]);
            sum += a[i][j];
        }
        printf("\n");
    }
    printf("%d", sum);
}