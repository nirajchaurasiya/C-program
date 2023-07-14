#include <stdio.h>
int main()
{
    int a, b, sum;
    printf("Enter first number: \n");
    scanf("%d", &a);
    printf("Enter second number\n");
    scanf("%d", &b);
    sum = a + b;
    printf("The sum of entered number %d and %d is %d", a, b, sum);
    return 0;
}