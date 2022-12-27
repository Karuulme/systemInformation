#include "kernelInfoClass.h"

void kernelInfoClass::getKernel() {
	LPSYSTEM_INFO lpSystemInfo=(LPSYSTEM_INFO)malloc(sizeof(LPSYSTEM_INFO));
	GetNativeSystemInfo(lpSystemInfo);
	cout<<"dwNumberOfProcessors ->"<< lpSystemInfo->dwNumberOfProcessors << endl;
	cout<<"dwPageSize ->"<< lpSystemInfo->dwPageSize << endl;
	cout<<"dwAllocationGranularity ->"<< lpSystemInfo->dwAllocationGranularity << endl;
	cout<<"dwActiveProcessorMask ->"<< lpSystemInfo->dwActiveProcessorMask << endl;
	cout<<"dwAllocationGranularity ->"<< lpSystemInfo->dwAllocationGranularity << endl;
	cout<<"dwNumberOfProcessors ->"<< lpSystemInfo->dwNumberOfProcessors << endl;
	cout<<"dwOemId ->"<< lpSystemInfo->dwOemId << endl;
	cout<<"dwPageSize ->"<< lpSystemInfo->dwPageSize << endl;
	cout<<"dwProcessorType ->"<< lpSystemInfo->dwProcessorType << endl;
	cout<<"lpMaximumApplicationAddress ->"<< lpSystemInfo->lpMaximumApplicationAddress << endl;
	cout<<"lpMinimumApplicationAddress ->"<< lpSystemInfo->lpMinimumApplicationAddress << endl;
	cout<<"wProcessorArchitecture ->"<< lpSystemInfo->wProcessorArchitecture << endl;
	cout<<"wProcessorLevel ->"<< lpSystemInfo->wProcessorLevel << endl;
	cout<<"wProcessorRevision ->"<< lpSystemInfo->wProcessorRevision << endl;
	cout<<"wReserved ->"<< lpSystemInfo->wReserved << endl;

}





