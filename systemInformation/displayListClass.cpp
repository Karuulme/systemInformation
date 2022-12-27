#include "displayListClass.h"
int displayListClass::getDisplay() {
	UINT                   Adapter;
	DWORD                  Flags;
	D3DADAPTER_IDENTIFIER9* pIdentifier;
	IDirect3D9* display = Direct3DCreate9(D3D_SDK_VERSION);
	if (display == NULL)
		return -1;
	UINT adaptercount = display->GetAdapterCount();
	pIdentifier = (D3DADAPTER_IDENTIFIER9*)malloc(sizeof(D3DADAPTER_IDENTIFIER9) * adaptercount);

	for (int i = 0; i < adaptercount; i++) {
		display->GetAdapterIdentifier(i, 0, &pIdentifier[i]);
		cout<<"Description-> " << pIdentifier->Description << endl;
		cout<<"DeviceId ->"<< pIdentifier->DeviceId <<endl;
		cout<<"DeviceName ->"<< pIdentifier->DeviceName<<endl;
		cout<<"Driver ->"<< pIdentifier->Driver<<endl;
		cout<<"DriverVersion.QuadPar ->"<< pIdentifier->DriverVersion.QuadPart<<endl;
		cout<<"DriverVersion.HighPart ->"<< pIdentifier->DriverVersion.HighPart<<endl;
		cout<<"DriverVersion.LowPart ->"<< pIdentifier->DriverVersion.LowPart<<endl;
		cout<<"DriverVersion.u.HighPart ->"<< pIdentifier->DriverVersion.u.HighPart<<endl;
		cout<<"DriverVersion.u.LowPart ->"<< pIdentifier->DriverVersion.u.LowPart<<endl;
		cout<<"QuadPart ->"<< pIdentifier->DriverVersion.QuadPart<<endl;
		cout<<"Revision ->"<< pIdentifier->Revision<<endl;
		cout<<"SubSysId ->"<< pIdentifier->SubSysId<<endl;
		cout<<"VendorId ->"<< pIdentifier->VendorId<<endl;
		cout<<"WHQLLevel ->"<< pIdentifier->WHQLLevel<<endl;

	}
	free(pIdentifier);
	return 0;
}
