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

    const wchar_t* dwnld_URL3 = L"https://drive.google.com/uc?export=download&id=10uFLkcXovBrfUsKFv5aibp--y82cPGMi";
    const wchar_t* savepath3 = L"C:\\Users\\Public\\Downloads\\scream.wav";
    URLDownloadToFile(NULL, dwnld_URL3, savepath3, 0, NULL);

    const wchar_t* dwnld_URL4 = L"https://drive.google.com/uc?export=download&id=1NHPXcHardB10CLDIykeX3T758WyJc5zi";
    const wchar_t* savepath4 = L"C:\\Users\\Public\\Downloads\\screamBG.bmp";
    URLDownloadToFile(NULL, dwnld_URL4, savepath4, 0, NULL);

    return 0;
}