#include <windows.h>

int Melt()
{
    HDC hdc = GetWindowDC(GetDesktopWindow());
    int x = 1920, y = 1080;

    BitBlt(hdc, rand() % 10 - 25, rand() % 25 - 10, x, y, hdc, 0, 0, SRCCOPY);
    return 0;
}
