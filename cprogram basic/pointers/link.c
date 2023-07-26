#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char link[256];

    // Prompt the user to enter the link
    printf("Enter the link URL: ");
    fgets(link, sizeof(link), stdin);

    // Remove the newline character from the link
    int link_length = strlen(link);
    if (link[link_length - 1] == '\n')
    {
        link[link_length - 1] = '\0';
    }

// The command to open the link varies depending on the platform
#ifdef _WIN32
    // For Windows, use the "start" command
    char command[512];
    snprintf(command, sizeof(command), "start %s", link);
#endif

    // Execute the command to open the link
    int result = system(command);

    if (result == -1)
    {
        printf("Failed to open the link.\n");
    }
    else
    {
        printf("Link opened successfully.\n");
    }

    return 0;
}
