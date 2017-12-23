#pragma once
#include "common.h"

#include "my_d3d.h"


extern LPDIRECTDRAW4 glp_DirectDraw4;

class FakeDirectDraw4: public IDirectDraw4
{
private:
	LPDIRECTDRAW lpOrigDirectDraw;
	LPDIRECTDRAW4 lpOrigDirectDraw4;
	LPDIRECT3D3 lpd3d3;
public:
	FakeDirectDraw4(LPDIRECTDRAW lpOrigDirectDraw)
	{
		LOG("DDRAW4 CREATED");
		LOG(__FUNCTION__);
		this->lpOrigDirectDraw = lpOrigDirectDraw;
		lpd3d3 = new FakeDirect3D3();

	}
    /*** IUnknown methods ***/
    STDMETHODIMP QueryInterface (THIS_ REFIID riid, LPVOID FAR * ppvObj) 
	{  
		LPVOID tmp;
		LOG(__FUNCTION__);

		fprintf(log, "%x-%x-%x-%x%x\n", riid.Data1, riid.Data2, riid.Data3, 
			(int)((int*)riid.Data4)[0], (int)((int*)riid.Data4)[4]);
		//lpOrigDirectDraw->QueryInterface(riid, (LPVOID*)&tmp);

		LOG("BEFORE QUERY_INTERFACE");
		lpOrigDirectDraw->QueryInterface(riid, (LPVOID*)&tmp);
		LOG("AFTER QUERY_INTERFACE");
		if (IsEqualIID(IID_IDirect3D3, riid))
		{
			*ppvObj = lpd3d3;
			glp_Direct3D3 = LPDIRECT3D3(tmp);
			LOG("THIS IS DIRECT_3D3");
		}
		return 0; 
	};
    STDMETHOD_(ULONG,AddRef) (THIS)  {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHOD_(ULONG,Release) (THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    /*** IDirectDraw methods ***/
    STDMETHODIMP Compact(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP CreateClipper(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP CreatePalette(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP CreateSurface(THIS_  LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE4 FAR *, IUnknown FAR *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP DuplicateSurface( THIS_ LPDIRECTDRAWSURFACE4, LPDIRECTDRAWSURFACE4 FAR * ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP EnumDisplayModes( THIS_ DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2 ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP EnumSurfaces(THIS_ DWORD, LPDDSURFACEDESC2, LPVOID,LPDDENUMSURFACESCALLBACK2 ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP FlipToGDISurface(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetCaps( THIS_ LPDDCAPS, LPDDCAPS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetDisplayMode( THIS_ LPDDSURFACEDESC2) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetFourCCCodes(THIS_  LPDWORD, LPDWORD ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetGDISurface(THIS_ LPDIRECTDRAWSURFACE4 FAR *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetMonitorFrequency(THIS_ LPDWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetScanLine(THIS_ LPDWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetVerticalBlankStatus(THIS_ LPBOOL ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP Initialize(THIS_ GUID FAR *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP RestoreDisplayMode(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP SetCooperativeLevel(THIS_ HWND, DWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP SetDisplayMode(THIS_ DWORD, DWORD,DWORD, DWORD, DWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP WaitForVerticalBlank(THIS_ DWORD, HANDLE ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    /*** Added in the v2 interface ***/
    STDMETHODIMP GetAvailableVidMem(THIS_ LPDDSCAPS2, LPDWORD, LPDWORD) 
	{  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    /*** Added in the V4 Interface ***/
    STDMETHODIMP GetSurfaceFromDC (THIS_ HDC, LPDIRECTDRAWSURFACE4 *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP RestoreAllSurfaces(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP TestCooperativeLevel(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetDeviceIdentifier(THIS_ LPDDDEVICEIDENTIFIER dID, DWORD second) 
	{  
		HRESULT hr;
		LOG(__FUNCTION__"");
		fprintf(log, "device vendor = %x\n", dID->dwVendorId);
		hr = glp_DirectDraw4->GetDeviceIdentifier(dID, second);
		fprintf(log, "device vendor = %x\n", dID->dwVendorId);
		fflush(log);
		return hr;
	}
	void SetDD4(LPDIRECTDRAW4 lpOrigDirectDraw4)
	{
		this->lpOrigDirectDraw4 = lpOrigDirectDraw4;
	}
};
class FakeDirectDraw: public IDirectDraw
{
private:
	IDirectDraw *lpOrigDirectDraw;
	LPDIRECTDRAW4 lpdd4;
public:
	FakeDirectDraw()
	{
		LOG(__FUNCTION__);
		lpdd4 = new FakeDirectDraw4(this);
		ddraw.DirectDrawCreate( NULL, &lpOrigDirectDraw, NULL );
		

	}

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(const IID &riid, void **ppvObject)
	{
		LPVOID tmp;
		LOG(__FUNCTION__);

		fprintf(log, "%x-%x-%x-%x%x\n", riid.Data1, riid.Data2, riid.Data3, 
			(int)((int*)riid.Data4)[0], (int)((int*)riid.Data4)[4]);
		lpOrigDirectDraw->QueryInterface(riid, (LPVOID*)&tmp);
		
		if (IsEqualIID(IID_IDirectDraw4, riid))
		{
			*ppvObject = (VOID*)lpdd4;
			glp_DirectDraw4 = LPDIRECTDRAW4(tmp);
			LOG("THIS IS DIRECT_DRAW4");
		}
		//else if
		return S_OK;
		
	}
	virtual ULONG STDMETHODCALLTYPE AddRef( void)
	{
		return 0;
	}
	virtual ULONG STDMETHODCALLTYPE Release( void)
	{
		LOG(__FUNCTION__"---PIZDEC");
		lpOrigDirectDraw->Release();
		return 0;
	}
	/*** IDirectDraw methods ***/
	STDMETHODIMP    Compact(void) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    CreateClipper(DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    CreatePalette(DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    CreateSurface(LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR *, IUnknown FAR *) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    DuplicateSurface(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR * ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    EnumDisplayModes(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    EnumSurfaces(DWORD, LPDDSURFACEDESC, LPVOID,LPDDENUMSURFACESCALLBACK ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    FlipToGDISurface(void) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetCaps(LPDDCAPS, LPDDCAPS) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetDisplayMode(LPDDSURFACEDESC) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetFourCCCodes(LPDWORD, LPDWORD ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetGDISurface(LPDIRECTDRAWSURFACE FAR *) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetMonitorFrequency(LPDWORD) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetScanLine(LPDWORD) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    GetVerticalBlankStatus(LPBOOL ) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    Initialize(GUID FAR *) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    RestoreDisplayMode(void) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    SetCooperativeLevel(HWND, DWORD) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    SetDisplayMode(DWORD, DWORD,DWORD) { LOG(__FUNCTION__); return 0; }
	STDMETHODIMP    WaitForVerticalBlank(DWORD, HANDLE ) { LOG(__FUNCTION__); return 0; }
};



