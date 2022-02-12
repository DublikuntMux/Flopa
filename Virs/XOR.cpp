#include <Windows.h>

int XOR() {
	HDC hdc = GetWindowDC(GetDesktopWindow());
    int x = 1920, y = 1080;

    BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, SRCINVERT);
    return 0;
}
