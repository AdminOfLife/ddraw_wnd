#include "common.h"



void install_hooks(ddraw_dll *ddraw)
{
	FPDirectDrawCreate test;
	ddraw->AcquireDDThreadLock			= GetProcAddress(ddraw->dll, "AcquireDDThreadLock");
	ddraw->CheckFullscreen				= GetProcAddress(ddraw->dll, "CheckFullscreen");
	ddraw->CompleteCreateSysmemSurface	= GetProcAddress(ddraw->dll, "CompleteCreateSysmemSurface");
	ddraw->D3DParseUnknownCommand		= GetProcAddress(ddraw->dll, "D3DParseUnknownCommand");
	ddraw->DDGetAttachedSurfaceLcl		= GetProcAddress(ddraw->dll, "DDGetAttachedSurfaceLcl");
	ddraw->DDInternalLock				= GetProcAddress(ddraw->dll, "DDInternalLock");
	ddraw->DDInternalUnlock				= GetProcAddress(ddraw->dll, "DDInternalUnlock");
	ddraw->DSoundHelp					= GetProcAddress(ddraw->dll, "DSoundHelp");
	ddraw->DirectDrawCreate				= (FPDirectDrawCreate)GetProcAddress(ddraw->dll, "DirectDrawCreate");
	ddraw->DirectDrawCreateClipper		= GetProcAddress(ddraw->dll, "DirectDrawCreateClipper");
	ddraw->DirectDrawCreateEx			= GetProcAddress(ddraw->dll, "DirectDrawCreateEx");
	ddraw->DirectDrawEnumerateA			= (FPDirectDrawEnumerateA)GetProcAddress(ddraw->dll, "DirectDrawEnumerateA");
	ddraw->DirectDrawEnumerateExA		= GetProcAddress(ddraw->dll, "DirectDrawEnumerateExA");
	ddraw->DirectDrawEnumerateExW		= GetProcAddress(ddraw->dll, "DirectDrawEnumerateExW");
	ddraw->DirectDrawEnumerateW			= GetProcAddress(ddraw->dll, "DirectDrawEnumerateW");
	ddraw->DllCanUnloadNow				= GetProcAddress(ddraw->dll, "DllCanUnloadNow");
	ddraw->DllGetClassObject			= GetProcAddress(ddraw->dll, "DllGetClassObject");
	ddraw->GetDDSurfaceLocal			= GetProcAddress(ddraw->dll, "GetDDSurfaceLocal");
	ddraw->GetOLEThunkData				= GetProcAddress(ddraw->dll, "GetOLEThunkData");
	ddraw->GetSurfaceFromDC				= GetProcAddress(ddraw->dll, "GetSurfaceFromDC");
	ddraw->RegisterSpecialCase			= GetProcAddress(ddraw->dll, "RegisterSpecialCase");
	ddraw->ReleaseDDThreadLock			= GetProcAddress(ddraw->dll, "ReleaseDDThreadLock");
}

