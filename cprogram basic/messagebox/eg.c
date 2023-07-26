#include <Windows.h>

int main()
{
    // Example 1: Simple MessageBox with an OK button
    MessageBox(NULL, "Hello, World!", "Message", MB_ICONINFORMATION | MB_OK);

    // Example 2: MessageBox with Yes/No buttons and an icon
    int response = MessageBox(NULL, "Do you like C programming?", "Question", MB_ICONQUESTION | MB_YESNO);
    if (response == IDYES)
    {
        MessageBox(NULL, "That's great!", "Response", MB_ICONINFORMATION | MB_OK);
    }
    else if (response == IDNO)
    {
        MessageBox(NULL, "Oh, maybe you'll like it later!", "Response", MB_ICONINFORMATION | MB_OK);
    }

    // Example 3: MessageBox with Retry/Cancel buttons and an icon
    response = MessageBox(NULL, "An error occurred. Retry?", "Error", MB_ICONERROR | MB_RETRYCANCEL);
    if (response == IDRETRY)
    {
        MessageBox(NULL, "Retry operation.", "Response", MB_ICONINFORMATION | MB_OK);
    }
    else if (response == IDCANCEL)
    {
        MessageBox(NULL, "Operation canceled.", "Response", MB_ICONINFORMATION | MB_OK);
    }

    return 0;
}
