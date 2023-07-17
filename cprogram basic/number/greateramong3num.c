#include <stdio.h>
int main()
{
    int a, b, c;
    printf("\nEnter a\n");
    scanf("%d", &a);
    printf("Enter b\n");
    scanf("%d", &b);
    printf("Enter c\n");
    scanf("%d", &c);
    if (a > b && a > c)
    {
        printf("%d is greater", a);
    }
    else if (b > c)
    {
        printf("%d is greater", b);
    }
    else
    {
        printf("%d is greater", c);
    }
    return 0;
}