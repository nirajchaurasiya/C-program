#include <stdio.h>
#include <string.h>

int main()
{
    int a;
top:
    printf("Enter a number:\n");
    scanf("%d", &a);
    if (a > 10)
    {
        printf("%d is greater than 10", a);
    }
    else
    {
        printf("%d is less than 10", a);
    }
    printf("\nExit program.\n");
    goto top;
}
