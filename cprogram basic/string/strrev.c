#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int i,l;
    char s1[] = "Niraj",ch;
    char rev[20];
    // strrev(s1);
    // printf("%s",s1);
    l = strlen(s1);
    for ( i = 0; i < l/2; i++)
    {
        ch = s1[i];
        s1[i] = s1[l-1-i];
        s1[l-1-i] = ch;
    }
    printf("%s",s1)
}