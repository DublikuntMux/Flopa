#include <Windows.h>

int Scuaer() {
	HDC hdc = GetWindowDC(GetDesktopWindow());
	HBRUSH hBrush;
	int sx = 1920, sy = 1080;

	hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, rand() % sx, rand() % sy, rand() % sx, rand() % sy);
	return 0;
}
