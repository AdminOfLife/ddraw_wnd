#include <windows.h>
#include <ddraw.h>

/************ TYPEDEFS ***********/
typedef HRESULT (WINAPI *FPDirectDrawCreate)( GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);

extern ULONG *FakeDD[3];

typedef struct
{
	HMODULE dll;
	FARPROC	AcquireDDThreadLock;
	FARPROC	CheckFullscreen;
	FARPROC	CompleteCreateSysmemSurface;
	FARPROC	D3DParseUnknownCommand;
	FARPROC	DDGetAttachedSurfaceLcl;
	FARPROC	DDInternalLock;
	FARPROC	DDInternalUnlock;
	FARPROC	DSoundHelp;
	FPDirectDrawCreate DirectDrawCreate;
	FARPROC	DirectDrawCreateClipper;
	FARPROC	DirectDrawCreateEx;
	FARPROC	DirectDrawEnumerateA;
	FARPROC	DirectDrawEnumerateExA;
	FARPROC	DirectDrawEnumerateExW;
	FARPROC	DirectDrawEnumerateW;
	FARPROC	DllCanUnloadNow;
	FARPROC	DllGetClassObject;
	FARPROC	GetDDSurfaceLocal;
	FARPROC	GetOLEThunkData;
	FARPROC	GetSurfaceFromDC;
	FARPROC	RegisterSpecialCase;
	FARPROC	ReleaseDDThreadLock;
} ddraw_dll;

void install_hooks(ddraw_dll *ddraw);