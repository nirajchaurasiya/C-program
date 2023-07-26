#include <Windows.h>

int main()
{
    const char *text = "Choose an option:";
    const char *title = "Options";
    int response = MessageBox(NULL, text, title, MB_ICONQUESTION | MB_YESNOCANCEL);

    if (response == IDYES)
    {
        MessageBox(NULL, "You clicked Yes!", "Result", MB_ICONINFORMATION | MB_OK);
    }
    else if (response == IDNO)
    {
        MessageBox(NULL, "You clicked No!", "Result", MB_ICONINFORMATION | MB_OK);
    }
    else if (response == IDCANCEL)
    {
        MessageBox(NULL, "You clicked Cancel!", "Result", MB_ICONINFORMATION | MB_OK);
    }

    return 0;
}
