/*
    Bitwise Operator (at Bit level)
    8 bit = 1 byte
    & => Bitwise AND,
    | Bitwise OR,
    ^ Bitwise XOR,
    ~ Bitwise NOT,
    << Left Shift,
    >> Right Shift
*/
#include <stdio.h>
#include <conio.h>
void main()
{
    // int << 2;

    // Bitwise AND
    // printf("%d", 5 & 4);
    // // Bitwise OR
    // printf("\n%d", 5 | 4);
    // // Bitwise XOR
    // printf("\n%d", 5 ^ 4);
    // // Bitwise NOT
    // // printf("\n%d", 5 !4);
    // // Left Shift
    // int a = 5;
    // int c = a << 2;
    // // printf("\n%d", 5 << 4); //80
    // printf("\n%d", c);
    // printf("\n%d", 1 << 2);

    // int b;
    // b = ~a;
    // printf("\n%d", b); // -6

    int a = 2;
    int c = (a + 1) << 2;
    int d = (a + 2) >> 1;
    int e = ~(a - 10);
    printf("%d \t%d \t%d", c, d, e);
}