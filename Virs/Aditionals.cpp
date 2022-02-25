#pragma comment(lib, "urlmon.lib")
#include <Windows.h>
#include <string>
using namespace std;

bool GetFileURL(const wchar_t* dwnld_URL, const wchar_t* savepath) {
	URLDownloadToFile(NULL, dwnld_URL, savepath, 0, NULL);
	return true;
}
bool CRK(HKEY key, wstring path, wstring name) {
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != NULL)
	{
		HKEY hKeyResult;
		RegCreateKeyW(hKey, name.c_str(), &hKeyResult);
		RegCloseKey(hKey);
	}
	return true;
}
bool DRK(HKEY key, wstring path, wstring name) {
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != NULL)
	{
		RegDeleteKeyW(hKey, name.c_str());
		RegCloseKey(hKey);
	}
	return true;
}
bool SRV(HKEY key, wstring path, wstring name, wstring value) {
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != NULL)
	{
		RegSetValueExW(hKey, name.c_str(), 0, REG_SZ, (BYTE*)value.c_str(), ((DWORD)wcslen(value.c_str()) + 1) * sizeof(wchar_t));
		RegCloseKey(hKey);
	}
	return true;
}
