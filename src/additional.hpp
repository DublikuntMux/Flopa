#ifndef ADITIONAL_H
#define ADITIONAL_H

#include <Windows.h>
#include <string>
using namespace std;

void GetFileURL(const wchar_t* URL, const wchar_t* patch);
void CRK(HKEY key, wstring path, wstring name);
void DRK(HKEY key, wstring path, wstring name);
void SRV(HKEY key, wstring path, wstring name, wstring value);

#endif
