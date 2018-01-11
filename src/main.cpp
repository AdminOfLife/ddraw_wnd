//------------------------------------------------------------------------------
// Tiny DirectDraw Proxy DLL v1.0 [28.05.2010]
// Copyright 2010 Evgeny Vrublevsky <veg@tut.by>
//------------------------------------------------------------------------------
#define APP_NAME		"Tiny DirectDraw Proxy"
#define APP_VERSION		"1.0 [28.05.2010]"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <ddraw.h>
#include <stdio.h>

#include "common.h"
#include "FakeDirectDrawN.h"

// Globals
FILE *log;
ddraw_dll ddraw;

LPDIRECTDRAW glp_DirectDraw;
LPDIRECTDRAW4 glp_DirectDraw4;
LPDIRECTDRAWSURFACE glp_DirectDrawSurface;
LPDIRECTDRAWSURFACE4 glp_DirectDrawSurface4;
LPDIRECT3D3 glp_Direct3D3;
LPDIRECT3DDEVICE3 glp_Direct3DDeviece3;
LPDIRECT3D7 glp_Direct3D7;
LPFAKEDIRECT3D3 glp_FakeDirect3D3;
LPFAKEDIRECTDRAW4 glp_FakeDirectDraw4;
LPFAKEDIRECT3DDEVICE3 glp_FakeDirect3DDevice3;

void InitDirectDraw()
{
	glp_DirectDraw = new FakeDirectDraw();
	glp_DirectDraw4 = new FakeDirectDraw4(glp_DirectDraw);
	LOG("---------------------------\n\n");
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	char path[MAX_PATH];
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			CopyMemory(path+GetSystemDirectory(path,MAX_PATH-10), "\\ddraw.dll",11);
			log = (FILE*)fopen("log.txt", "w");
			LOG("Log openned");
			fflush(log);

			ddraw.dll = LoadLibrary(path);
			if (ddraw.dll == false)
			{
				MessageBox(0, "Cannot load original ddraw.dll library", APP_NAME, MB_ICONERROR);
				ExitProcess(0);
			}
			install_hooks(&ddraw);
			/********************/
			//InitDirectDraw();
			/********************/
			LoadLibrary("wndmode.dll");
		break;

		case DLL_PROCESS_DETACH:
			FreeLibrary(ddraw.dll);
			fclose(log);
		break;
	}
	return TRUE;
}