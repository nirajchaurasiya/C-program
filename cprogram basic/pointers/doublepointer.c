/*
 A pointer must point to a pointer only
 eg:
    a => 10;
    *p => &a;
    **q => &p;
*/

#include <stdio.h>

void main()

{
    int a = 10;
    int *p = &a;
    printf("%d\n", p);  // address
    printf("%d\n", *p); // value
    int **q = &p;
    printf("%d", *q);
}