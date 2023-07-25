#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    /*
    char s1[30] = "Niraj";
    char s2[20] = "Niraj";
    if (strcmp(s1, s2) == 0)
    {
        printf("Matched"); // Matched
    }
    else
    {
        printf("!Matched");
    }
    */
   int i,flag=0;
    char s1[30] = "Chaurasiya";
    char s2[20] = "Chaurasiy a";
    for(i=0;s1[i]!='\0'||s2[i]!='\0';i++){
        if(s1[i]!=s2[i]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        // Not matched
        printf("Not Matched");
    }
    else{
        // Match
        printf("Matched");
    }
}