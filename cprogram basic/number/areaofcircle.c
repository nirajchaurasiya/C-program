// Program to print the area of the circle
#include <stdio.h>
int main()
{
    float radius, area;
    printf("Radius = ?");
    scanf("\n%f", &radius);
    area = 3.1415 * radius * radius;
    printf("Area is %f", area);
    return 0;
}
