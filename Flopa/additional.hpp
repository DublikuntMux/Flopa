#ifndef ADITIONAL_H
#define ADITIONAL_H

#include <Windows.h>
#include <string>

void GetFileURL(const wchar_t* URL, const wchar_t* patch);
void CRK(HKEY key, std::wstring path, std::wstring name);
void DRK(HKEY key, std::wstring path, std::wstring name);
void SRV(HKEY key, std::wstring path, std::wstring name, std::wstring value);

#endif
