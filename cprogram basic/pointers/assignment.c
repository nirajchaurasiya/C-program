#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
int main()
{
    int a = 10, b = 11;
    int *p, *q;
    p = &a, q = &b;
    // q = p;
    // printf("a = %d %d %d", a, *p, *q);
    *q = *p;
    printf("a = %d %d %d", a, *p, *q);
    return 0;
}