#pragma once

extern LPDIRECTDRAW4 glp_DirectDraw4;

class FakeDirectDraw4: public IDirectDraw4
{
public:
	FakeDirectDraw4()
	{
		LOG(__FUNCTION__);
	}
    /*** IUnknown methods ***/
    STDMETHODIMP QueryInterface (THIS_ REFIID riid, LPVOID FAR * ppvObj) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
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
    STDMETHODIMP GetAvailableVidMem(THIS_ LPDDSCAPS2, LPDWORD, LPDWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    /*** Added in the V4 Interface ***/
    STDMETHODIMP GetSurfaceFromDC (THIS_ HDC, LPDIRECTDRAWSURFACE4 *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP RestoreAllSurfaces(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP TestCooperativeLevel(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetDeviceIdentifier(THIS_ LPDDDEVICEIDENTIFIER, DWORD ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
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
		lpdd4 = glp_DirectDraw4;
		ddraw.DirectDrawCreate( NULL, &lpOrigDirectDraw, NULL );

	}

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(const IID &riid, void **ppvObject)
	{
		LOG(__FUNCTION__"---PIZDEC");
		fprintf(log, "%x\n", riid.Data1);
		*ppvObject = (VOID*)lpdd4;
		lpOrigDirectDraw->QueryInterface(riid, ppvObject);
		return S_OK;
		
	}
	virtual ULONG STDMETHODCALLTYPE AddRef( void)
	{
		return 0;
	}
	virtual ULONG STDMETHODCALLTYPE Release( void)
	{
		LOG(__FUNCTION__"---PIZDEC");
		return 0;
	}
	/*** IDirectDraw methods ***/
	STDMETHODIMP    Compact(THIS) { return 0; }
	STDMETHODIMP    CreateClipper(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR * ) { return 0; }
	STDMETHODIMP    CreatePalette(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) { return 0; }
	STDMETHODIMP    CreateSurface(THIS_  LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR *, IUnknown FAR *) { return 0; }
	STDMETHODIMP    DuplicateSurface( THIS_ LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR * ) { return 0; }
	STDMETHODIMP    EnumDisplayModes( THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK ) { return 0; }
	STDMETHODIMP    EnumSurfaces(THIS_ DWORD, LPDDSURFACEDESC, LPVOID,LPDDENUMSURFACESCALLBACK ) { return 0; }
	STDMETHODIMP    FlipToGDISurface(THIS) { return 0; }
	STDMETHODIMP    GetCaps( THIS_ LPDDCAPS, LPDDCAPS) { return 0; }
	STDMETHODIMP    GetDisplayMode( THIS_ LPDDSURFACEDESC) { return 0; }
	STDMETHODIMP    GetFourCCCodes(THIS_  LPDWORD, LPDWORD ) { return 0; }
	STDMETHODIMP    GetGDISurface(THIS_ LPDIRECTDRAWSURFACE FAR *) { return 0; }
	STDMETHODIMP    GetMonitorFrequency(THIS_ LPDWORD) { return 0; }
	STDMETHODIMP    GetScanLine(THIS_ LPDWORD) { return 0; }
	STDMETHODIMP    GetVerticalBlankStatus(THIS_ LPBOOL ) { return 0; }
	STDMETHODIMP    Initialize(THIS_ GUID FAR *) { return 0; }
	STDMETHODIMP    RestoreDisplayMode(THIS) { return 0; }
	STDMETHODIMP    SetCooperativeLevel(THIS_ HWND, DWORD) { return 0; }
	STDMETHODIMP    SetDisplayMode(THIS_ DWORD, DWORD,DWORD) { return 0; }
	STDMETHODIMP    WaitForVerticalBlank(THIS_ DWORD, HANDLE ) { return 0; }
};



