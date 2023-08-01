#include <stdio.h>
#include <conio.h>
void main()
{
    int a[] = {10, 11, -1, 56, 67, 5, 4};
    int *p, *q;
    p = a;
    printf("%d\n", *p); // 10
    printf("%d\t%d\t%d", (*p)++, *p++, *++p);
}