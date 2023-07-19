#include <stdio.h>
#include <string.h>

int main()
{
    char ch[10];

    printf("Enter a string (up to 9 characters): ");
    fgets(ch, sizeof(ch), stdin);

    // Removing the trailing newline character, if present
    if (ch[strlen(ch) - 1] == '\n')
    {
        ch[strlen(ch) - 1] = '\0';
    }

    printf("You entered: %s\n", ch);

    return 0;
}
