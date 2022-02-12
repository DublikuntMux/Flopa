#include <Windows.h>

int TextO() {
	HDC hdc; 
	int sx = 1920, sy = 1080; 
	LPCWSTR lpText = L"I want to find myself!"; 

	hdc = GetWindowDC(GetDesktopWindow());
	SetTextColor(hdc, RGB(255, 0, 0));
	SetBkColor(hdc, RGB(0, 0, 0));
	TextOutW(hdc, rand() % sx, rand() % sy, lpText, wcslen(lpText));
	return 0;
}
