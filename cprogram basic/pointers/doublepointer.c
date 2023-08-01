/*
 A pointer must point to a pointer only
 eg:
    a => 10;
    *p => &a;
    **q => &p;
    ***r => &q;
    Answer =) ***r = **(*1046) = *(*850) = *(1000) = 10
*/

#include <stdio.h>
void main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;
    // *q = 25; Error
    int ***r = &q;

    printf("%d\n", p);  // address
    printf("%d\n", *p); // value
    printf("%d\n", *q);
    printf("%d", ***r);
}