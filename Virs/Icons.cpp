#include <Windows.h>

int Icons() {
	HDC hdc = GetWindowDC(GetDesktopWindow());
	int x = rand() % 1920;
	int y = rand() % 1080;
	DrawIcon(hdc, x, y, LoadIcon(0, IDI_WARNING));
	x = rand() % 1920;
	y = rand() % 1080;
	DrawIcon(hdc, x, y, LoadIcon(0, IDI_QUESTION));
	x = rand() % 1920;
	y = rand() % 1080;
	DrawIcon(hdc, x, y, LoadIcon(0, IDI_INFORMATION));
	x = rand() % 1920;
	y = rand() % 1080;
	DrawIcon(hdc, x, y, LoadIcon(0, IDI_ERROR));
	return 0;
}
