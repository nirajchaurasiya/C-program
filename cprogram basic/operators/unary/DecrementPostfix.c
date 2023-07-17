// Unary Operator
// Decrement
#include <stdio.h>
#include <conio.h>
void main()
{
    int x = 11;
    int y = 10;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    y = x--; // Post fix
    printf("x = %d\n", x);
    printf("y = %d\n", y);
}