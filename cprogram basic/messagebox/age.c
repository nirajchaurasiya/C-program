#include <Windows.h>
#include <CommCtrl.h>

#pragma comment(lib, "Comctl32.lib")

INT_PTR CALLBACK AgeInputDialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static char ageString[10];

    switch (message)
    {
    case WM_INITDIALOG:
        SetWindowText(hWnd, "Age Input");
        CreateWindow("STATIC", "Enter your age:", WS_VISIBLE | WS_CHILD | SS_CENTER, 10, 10, 180, 20, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 50, 40, 100, 20, hWnd, (HMENU)1, NULL, NULL);
        CreateWindow("BUTTON", "OK", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 40, 70, 60, 24, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("BUTTON", "Cancel", WS_VISIBLE | WS_CHILD, 110, 70, 60, 24, hWnd, (HMENU)IDCANCEL, NULL, NULL);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            GetDlgItemText(hWnd, 1, ageString, sizeof(ageString));
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
    char ageString[10];
    int age;

    HINSTANCE hInstance = GetModuleHandle(NULL);
    INITCOMMONCONTROLSEX icc;
    icc.dwSize = sizeof(icc);
    icc.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&icc);

    int response = DialogBoxParam(hInstance, NULL, NULL, AgeInputDialogProc, 0);

    if (response == IDOK)
    {
        age = atoi(ageString);

        if (age >= 18)
        {
            MessageBox(NULL, "You are old enough to vote!", "Voting Eligibility", MB_ICONINFORMATION | MB_OK);
        }
        else
        {
            MessageBox(NULL, "You are not old enough to vote!", "Voting Eligibility", MB_ICONINFORMATION | MB_OK);
        }
    }

    return 0;
}
