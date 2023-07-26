#include <Windows.h>

INT_PTR CALLBACK CustomDialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            EndDialog(hWnd, IDOK);
        }
        else if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hWnd, IDCANCEL);
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int main()
{
    const char *text = "This is a custom dialog box.";
    const char *title = "Custom Dialog Box";
    HINSTANCE hInstance = GetModuleHandle(NULL);

    HWND hWnd = CreateDialogParam(hInstance, NULL, NULL, CustomDialogProc, 0);
    if (hWnd == NULL)
    {
        MessageBox(NULL, "Failed to create dialog.", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    SetWindowText(hWnd, title);
    CreateWindow("STATIC", text, WS_VISIBLE | WS_CHILD | SS_CENTER, 10, 10, 180, 40, hWnd, NULL, hInstance, NULL);
    CreateWindow("BUTTON", "OK", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 30, 60, 80, 24, hWnd, (HMENU)IDOK, hInstance, NULL);
    CreateWindow("BUTTON", "Cancel", WS_VISIBLE | WS_CHILD, 120, 60, 80, 24, hWnd, (HMENU)IDCANCEL, hInstance, NULL);

    ShowWindow(hWnd, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!IsDialogMessage(hWnd, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}
