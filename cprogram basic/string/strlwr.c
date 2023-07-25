#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char s1[20] = "NiRaJ!@#$";
    int i;
    for ( i = 0; s1[i]!='\0' ; i++)
    {
        if(s1[i]>=65&&s1[i]<=90){
            s1[i] = s1[i]+32;
        }
    }
    printf("%s",s1);
}