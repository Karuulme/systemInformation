#include "storagePartitionsClass.h"
double storagePartitionsClass::byteToGb(long double byte) {
	double kilobyte;
	double megabyte;
	double gigabyte;
	kilobyte = byte / 1024;
	megabyte = kilobyte / 1024;
	gigabyte = megabyte / 1024;

	return gigabyte;
}
void  storagePartitionsClass::storageList() {
	WCHAR  lpszVolumeName[MAX_PATH] = L"";
	DWORD index = 0;
	WCHAR  deviceName[MAX_PATH] = L"";
	DWORD  CharCount = MAX_PATH + 1;
	PWCHAR Names = NULL;
	ULARGE_INTEGER p1, p2, p3;
	HANDLE diskHandle = FindFirstVolumeW(lpszVolumeName, ARRAYSIZE(lpszVolumeName));
	do {
		Names = (PWCHAR) new BYTE[CharCount * sizeof(WCHAR)];
		if (GetVolumePathNamesForVolumeNameW(lpszVolumeName, Names, CharCount, &CharCount) == 0)
			break;
		wstring ws(Names);
		string address(ws.begin(), ws.end());
		if (GetDiskFreeSpaceExA(address.c_str(), &p1, &p2, &p3) != 0) {
			cout << "-------------------------------" << endl;
			cout << address << endl;
			cout << "Dolu Alan " << byteToGb(p2.QuadPart) << endl;
			cout << "Bos Alan  " << byteToGb(p1.QuadPart) << endl;
			cout << "-------------------------------" << endl;
		}
	} while (FindNextVolumeW(diskHandle, lpszVolumeName, ARRAYSIZE(lpszVolumeName)));
	FindVolumeClose(diskHandle);
};
/*
https://www.daniweb.com/programming/software-development/code/230334/byte-to-kilobyte-conversion-in-c
MSDN
*/

