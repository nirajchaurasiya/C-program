#include <stdio.h>
#include <conio.h>
void main()
{
    int i;
    int multi_num, user_ans;
top:
    printf("Enter a number:\n");
    scanf("%d", &multi_num);
    for (i = 0; i < 10; i++)
    {
        printf("\n%d * %d = %d", multi_num, i + 1, multi_num * (i + 1));
    }
    printf("\nDo you want to print another number?\nEnter any number to continue or 0 to terminate.\n");
    scanf("%d", &user_ans);
    if (user_ans != 0)
    {
        goto top;
    }
    else
    {
        printf("Terminated");
    }
}