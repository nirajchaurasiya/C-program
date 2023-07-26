#include <Windows.h>

int main()
{
    const char *text = "Do you want to proceed?";
    const char *title = "Confirmation";
    int response = MessageBox(NULL, text, title, MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2);

    if (response == IDYES)
    {
        MessageBox(NULL, "Proceeding...", "Status", MB_ICONINFORMATION | MB_OK);
    }
    else if (response == IDNO)
    {
        MessageBox(NULL, "Operation canceled.", "Status", MB_ICONINFORMATION | MB_OK);
    }

    return 0;
}
