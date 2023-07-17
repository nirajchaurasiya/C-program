#include <stdio.h>
#include <conio.h>
void main()
{
    int a = 10;
    float b = 10.0;
    char c = 'c';
    printf("%d\n", sizeof(int));   // 4 Byte
    printf("%d\n", sizeof(float)); // 4 Byte
    printf("%d\n", sizeof(char));  // 1 Byte
    printf("%d\n", sizeof(a));     // 4 Byte
    printf("%d\n", sizeof(b));     // 4 Byte
    printf("%d", sizeof(c));       // 1 Byte
}