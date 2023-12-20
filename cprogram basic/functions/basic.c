#include <stdio.h>
#include <conio.h>
int sum(int a, int b)
{
    printf("Enter two number:\n");
    scanf("%d \t %d", &a, &b);
    return a + b;
}

void main()
{
    int a, b, add;
    add = sum(a, b);
    printf("Sum = %d", add);
    return 0;
}