#include <Windows.h>

int main()
{
    const char *text = "Please click Help for more information.";
    const char *title = "Help Example";
    int response = MessageBox(NULL, text, title, MB_ICONINFORMATION | MB_OK | MB_HELP);

    if (response == IDOK)
    {
        // User clicked OK, do something...
    }
    else if (response == IDHELP)
    {
        MessageBox(NULL, "You clicked Help!", "Help Information", MB_ICONINFORMATION | MB_OK);
    }

    return 0;
}
