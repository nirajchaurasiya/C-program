// Program to print the area of the circle
#include <stdio.h>
#include <conio.h>
#define MAX 100;

int display();
int main()
{
    float radius, area;
    printf("Radius = ?");
    scanf("\n%f", &radius);
    area = 3.1415 * radius * radius;
    printf("Area is %f\n", area);
    printf("hello\n");
    printf("%d", display());
    return 0;
    // getch();
}
int display()
{
    return MAX;
}
