#include<Windows.h>

#pragma comment(lib, "urlmon.lib")

using namespace std;

int Download() {
    const wchar_t* dwnld_URL = L"https://drive.google.com/uc?export=download&id=1hEGfM2a3CI__Zb1E9ra9o-Rk4UB_VG4J";
    const wchar_t* savepath = L"C:\\Users\\Public\\Downloads\\BG.wav";
    URLDownloadToFile(NULL, dwnld_URL, savepath, 0, NULL);

    const wchar_t* dwnld_URL2 = L"https://drive.google.com/uc?export=download&id=1QSB8qiO7UNal3DRVcNksGqt7blJvfO7d";
    const wchar_t* savepath2 = L"C:\\Users\\Public\\Downloads\\WP.bmp";
    URLDownloadToFile(NULL, dwnld_URL2, savepath2, 0, NULL);

    char* str = "C:\\Users\\Public\\Downloads\\WP.bmp";
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    return 0;
}