#include <bits/stdc++.h>
#include <windows.h>
signed main() {
    HWND hWnd = FindWindow(nullptr, "ÆÁÄ»¹ã²¥");
    if (hWnd)
        puts("Found");
    else
        puts("Not found");
    SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    return 0;
}