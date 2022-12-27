#include "ramClass.h"

int ramClass::getRam() {
	ULONGLONG TotalMemoryInKilobytes;
	if (GetPhysicallyInstalledSystemMemory(&TotalMemoryInKilobytes) == TRUE)
		return TotalMemoryInKilobytes;
	return 0;
}
