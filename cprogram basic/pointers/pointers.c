#include<stdio.h>
#include<conio.h>
void main()
{
    int a = 10,b=9;
    int *p,*q;
    p = &a; // -1193281604 
    // q = &p; // -1193281616
    q = &b; // -692062120
    printf("%x\t%x",p,q);
    // value
    printf("\n%d\t%d",*p,*q);
}