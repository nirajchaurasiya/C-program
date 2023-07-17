#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main()
{
    FILE *fp;
    // char ch;
    char str[50];
    fp = fopen("abc.txt", "r");
    if (fp == NULL)
    {
        printf("Error, file not found");
        exit(1);
    }
    system("cls");
    // while (!feof(fp))
    // {
    //     ch = fgetc(fp);
    //     printf("%c", ch);
    // }

    fgets(str, 5, fp);
    printf("%s", str);
    fclose(fp);
}

/*
    To read
    fgetc
    fgets
*/