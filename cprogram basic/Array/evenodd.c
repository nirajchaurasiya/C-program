#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10], even = 0, odd = 0;
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    printf("Odd = %d and Even = %d", odd, even);
}