#pragma comment(lib, "urlmon.lib")

#include <Windows.h>
#include <string>

void GetFileURL(const wchar_t* URL, const wchar_t* patch) {
	URLDownloadToFile(nullptr, URL, patch, 0, nullptr);
}

void CRK(HKEY key, std::wstring path, std::wstring name) {
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != nullptr)
	{
		HKEY hKeyResult;
		RegCreateKeyW(hKey, name.c_str(), &hKeyResult);
		RegCloseKey(hKey);
	}
}

void DRK(HKEY key, std::wstring path, std::wstring name) {
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != nullptr)
	{
		RegDeleteKeyW(hKey, name.c_str());
		RegCloseKey(hKey);
	}
}

void SRV(HKEY key, std::wstring path, std::wstring name, std::wstring value) {
	HKEY hKey;
	if (RegOpenKeyExW(key, path.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS && hKey != nullptr)
	{
		RegSetValueExW(hKey, name.c_str(), 0, REG_SZ, (BYTE*)value.c_str(), ((DWORD)wcslen(value.c_str()) + 1) * sizeof(wchar_t));
		RegCloseKey(hKey);
	}
}
