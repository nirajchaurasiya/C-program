#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    float a = 21332.213123;
    // printf("%5.2f", a); // 21332.21
    // printf("%3.2f", a); // 21332.21
    // printf("\n%.2f", a); // 21332.21
    // printf("%.3f", a); //21332.213
    for (int i = 0; i < 5; i++)
    {
        printf("%.if\t", a);
    }

    return 0;
}
