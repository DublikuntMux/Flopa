#include <Windows.h>

int x = 1920, y = 1080;
HDC hdc = GetWindowDC(GetDesktopWindow());
HBRUSH hBrush;

int Icons() {
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(0, IDI_WARNING));
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(0, IDI_QUESTION));
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(0, IDI_INFORMATION));
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(0, IDI_ERROR));
	return 0;
}

int Invers() {
	BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, DSTINVERT);
	return 0;
}

int Melt() {
	BitBlt(hdc, rand() % 10 - 25, rand() % 25 - 10, x, y, hdc, 0, 0, SRCCOPY);
	return 0;
}

int Scuaer(int red, int green, int blue) {	
	hBrush = CreateSolidBrush(RGB(red, green, blue));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, rand() % x, rand() % y, rand() % x, rand() % y);
	return 0;
}

int TextO(LPCWSTR lpText) {
	SetTextColor(hdc, RGB(255, 0, 0));
	SetBkColor(hdc, RGB(0, 0, 0));
	TextOutW(hdc, rand() % x, rand() % y, lpText, wcslen(lpText));
	return 0;
}
