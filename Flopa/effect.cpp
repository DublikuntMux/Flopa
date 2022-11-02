#pragma comment(lib,"Advapi32")

#include <Windows.h>

int x = 1920, y = 1080;
auto hdc = GetWindowDC(GetDesktopWindow());
struct tagRECT Rect;
HBRUSH hBrush;

void Icons() {
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_QUESTION));
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_INFORMATION));
	DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
}

void Inversion() {
	BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, DSTINVERT);
}

void Melt() {
	BitBlt(hdc, rand() % 10 - 25, rand() % 25 - 10, x, y, hdc, 0, 0, SRCCOPY);
}

void Square(int red, int green, int blue) {
	hBrush = CreateSolidBrush(RGB(red, green, blue));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, rand() % x, rand() % y, rand() % x, rand() % y);
}

void TextO(LPCWSTR lpText) {
	SetTextColor(hdc, RGB(255, 0, 0));
	SetBkColor(hdc, RGB(0, 0, 0));
	TextOutW(hdc, rand() % x, rand() % y, lpText, wcslen(lpText));
}
