#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fp = NULL;
    int a = 10;
    char string[50] = "Niraj Chaurasiya";
    char str[50];
    fp = fopen("abc.txt", "a+");
    // for (int i = 0; i < strlen(string); i++)
    // {
    //     fputc(string[i], fp);
    // }
    if (fp == NULL)
    {
        printf("No file found");
        exit(1);
    }
    system("cls");
    printf("Enter the string\n");
    gets(str);

    // fprintf(fp, "\n %d \n %s", a, str);
    fputs(str, fp);
    printf("Entered successfully");
    fclose(fp);
}

/*
    r,
    w => Rewrite the text,
    a => Write it all by appending previous text too
    // r+ w+ a+
    To write
    fprintc
    fputs
    fprint
*/