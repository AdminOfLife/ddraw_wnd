#pragma once

#include <stdio.h>
#include "ddraw_dll.h"
#include "utils.h"

#include <ddraw.h>
#include <d3d.h>
#include <GuidDef.h>

class FakeDirect3D3;
class FakeDirect3DDevice3;
class FakeDirectDraw4;
typedef FakeDirect3D3 *LPFAKEDIRECT3D3;
typedef FakeDirect3DDevice3 *LPFAKEDIRECT3DDEVICE3;
typedef FakeDirectDraw4 *LPFAKEDIRECTDRAW4;

/************ GLOBALS *************/
extern ddraw_dll ddraw;
extern FILE *log;
extern LPDIRECTDRAW glp_DirectDraw;
extern LPDIRECTDRAW4 glp_DirectDraw4;
extern LPDIRECTDRAWSURFACE glp_DirectDrawSurface;
extern LPDIRECTDRAWSURFACE4 glp_DirectDrawSurface4;
extern LPDIRECT3D3 glp_Direct3D3;
extern LPDIRECT3D7 glp_Direct3D7;
extern LPDIRECT3DDEVICE3 glp_Direct3DDeviece3;
extern LPFAKEDIRECT3D3 glp_FakeDirect3D3;
extern LPFAKEDIRECTDRAW4 glp_FakeDirectDraw4;
extern LPFAKEDIRECT3DDEVICE3 glp_FakeDirect3DDevice3;

/************ DEFINES *************/
#define NAKEDCALL __declspec(naked)
// Logging
#define LOG(a) fprintf(log, a##"\n")
#define LOG_NAME "log.txt"
#define LOG_CREATE() FILE *log;\
	log = (FILE*)fopen(LOG_NAME, "w");





