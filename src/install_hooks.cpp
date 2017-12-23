#include "common.h"
#include "FakeDirectDrawN.h"
#include "my_d3d.h"


// Globals

ULONG *FakeDD[3];


NAKEDCALL void FakeAcquireDDThreadLock()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.AcquireDDThreadLock] } }
NAKEDCALL void FakeCheckFullscreen()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.CheckFullscreen] } }
NAKEDCALL void FakeCompleteCreateSysmemSurface()	{ LOG(__FUNCTION__);  _asm { jmp [ddraw.CompleteCreateSysmemSurface] } }
NAKEDCALL void FakeD3DParseUnknownCommand()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.D3DParseUnknownCommand] } }
NAKEDCALL void FakeDDGetAttachedSurfaceLcl()		{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DDGetAttachedSurfaceLcl] } }
NAKEDCALL void FakeDDInternalLock()					{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DDInternalLock] } }
NAKEDCALL void FakeDDInternalUnlock()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DDInternalUnlock] } }
NAKEDCALL void FakeDSoundHelp()						{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DSoundHelp] } }
// HRESULT WINAPI DirectDrawCreate( GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter );
HRESULT WINAPI FakeDirectDrawCreate( GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter )			
{ 
	LOG(__FUNCTION__);
	//IDirectDraw *fdd = new FakeDirectDraw();
	*lplpDD = new FakeDirectDraw();
	//*lplpDD = glp_DirectDraw;
	
	//MessageBox(NULL, "FUCK", "MUCK", MB_OK);
	//LOG(__FUNCTION__);  _asm { jmp [ddraw.DirectDrawCreate] }
	fprintf(log, "Pointer to GUID = %p\n", lpGUID);
	//fprintf(log, "test\n");
	//ddraw.DirectDrawCreate( NULL, lplpDD, pUnkOuter );
	LOG("Return from "__FUNCTION__);
	return 0;
}
// HRESULT WINAPI DirectDrawCreateClipper( DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter );
NAKEDCALL void FakeDirectDrawCreateClipper()		{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DirectDrawCreateClipper] } }
// HRESULT WINAPI DirectDrawCreateEx( GUID FAR * lpGuid, LPVOID *lplpDD, REFIID iid,IUnknown FAR *pUnkOuter );
NAKEDCALL void FakeDirectDrawCreateEx()				
{ 
	LOG(__FUNCTION__);
	_asm { jmp [ddraw.DirectDrawCreateEx] } 
}// HRESULT WINAPI DirectDrawEnumerateA( LPDDENUMCALLBACKA lpCallback, LPVOID lpContext );
NAKEDCALL void FakeDirectDrawEnumerateA()			
{
	LOG(__FUNCTION__);
	_asm { jmp [ddraw.DirectDrawEnumerateA] } 
}
// HRESULT WINAPI DirectDrawEnumerateExA( LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags );
NAKEDCALL void FakeDirectDrawEnumerateExA()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DirectDrawEnumerateExA] } }
// HRESULT WINAPI DirectDrawEnumerateExW( LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags );
NAKEDCALL void FakeDirectDrawEnumerateExW()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DirectDrawEnumerateExW] } }
// HRESULT WINAPI DirectDrawEnumerateW( LPDDENUMCALLBACKW lpCallback, LPVOID lpContext );
NAKEDCALL void FakeDirectDrawEnumerateW()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DirectDrawEnumerateW] } }
NAKEDCALL void FakeDllCanUnloadNow()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DllCanUnloadNow] } }
NAKEDCALL void FakeDllGetClassObject()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.DllGetClassObject] } }
NAKEDCALL void FakeGetDDSurfaceLocal()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.GetDDSurfaceLocal] } }
NAKEDCALL void FakeGetOLEThunkData()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.GetOLEThunkData] } }
NAKEDCALL void FakeGetSurfaceFromDC()				{ LOG(__FUNCTION__);  _asm { jmp [ddraw.GetSurfaceFromDC] } }
NAKEDCALL void FakeRegisterSpecialCase()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.RegisterSpecialCase] } }
NAKEDCALL void FakeReleaseDDThreadLock()			{ LOG(__FUNCTION__);  _asm { jmp [ddraw.ReleaseDDThreadLock] } }