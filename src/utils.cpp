#include "common.h"

void PrintGUID(REFCLSID cls)
{
	fprintf(log, "PRINT_GUID:\n%X-%X-%X-%X%X\n", cls.Data1, cls.Data2, cls.Data3, 
				(int)((int*)cls.Data4)[0], (int)((int*)cls.Data4)[4]);
}