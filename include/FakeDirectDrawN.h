#pragma once
#include "common.h"

#include "my_d3d.h"
#include "DirectDrawSurface4.h"


extern LPDIRECTDRAW4 glp_DirectDraw4;

class FakeDirectDraw4: public IDirectDraw4
{
private:
	LPDIRECTDRAW lpOrigDirectDraw;
	LPDIRECTDRAW4 lpOrigDirectDraw4;
	LPDIRECTDRAWSURFACE4 lpOrigDirectDrawSurface4;
	LPDIRECT3D3 lpd3d3;
	LPDDENUMCALLBACK origCallBack;
public:
	FakeDirectDraw4(LPDIRECTDRAW lpOrigDirectDraw)
	{
		LOG("DDRAW4 CREATED");
		LOG(__FUNCTION__);
		this->lpOrigDirectDraw = lpOrigDirectDraw;
		lpd3d3 = glp_FakeDirect3D3 = new FakeDirect3D3();
		lpOrigDirectDrawSurface4 = new FakeDirectDrawSurface4();
		//lpd3d3 = new FakeDirect3D3();

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
		glp_DirectDraw4->QueryInterface(riid, (LPVOID*)&tmp);
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
    STDMETHOD_(ULONG,Release) (THIS) 
	{  
		LOG(__FUNCTION__"---PIZDEC"); 
		glp_DirectDraw4->Release();
		return 0; 
	};
    /*** IDirectDraw methods ***/
    STDMETHODIMP Compact(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP CreateClipper(THIS_ DWORD first, LPDIRECTDRAWCLIPPER FAR* second, IUnknown FAR * ) 
	{  
		LOG(__FUNCTION__"---PIZDEC"); 
		glp_DirectDraw4->CreateClipper(first, second, NULL);
		return 0; 
	};
    STDMETHODIMP CreatePalette(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR * ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP CreateSurface(
	  LPDDSURFACEDESC2 lpDDSurfaceDesc2,        
	  LPDIRECTDRAWSURFACE4 FAR *lplpDDSurface,  
	  IUnknown FAR *pUnkOuter                  
	)
	{
		HRESULT hr;
		LOG(__FUNCTION__"---PIZDEC"); 
		hr = glp_DirectDraw4->CreateSurface(lpDDSurfaceDesc2, lplpDDSurface, pUnkOuter);
		return hr;
		//return 0; 
	};
    STDMETHODIMP DuplicateSurface( THIS_ LPDIRECTDRAWSURFACE4, LPDIRECTDRAWSURFACE4 FAR * ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP EnumDisplayModes( THIS_ DWORD first, LPDDSURFACEDESC2 second, LPVOID third, LPDDENUMMODESCALLBACK2 quad) 
	{  
		LOG(__FUNCTION__"---PIZDEC"); 
		if (second != NULL)
		{
			fprintf(log, "number of back buffers requested: \n", second->dwBackBufferCount);
		}
		else fprintf(log, "second failed\n");
		glp_DirectDraw4->EnumDisplayModes(first, second, third, quad);
		if (second != NULL)
		{
			fprintf(log, "number of back buffers requested: \n", second->dwBackBufferCount);
		}
		else fprintf(log, "second failed\n");
		return 0; 
	
	};
    STDMETHODIMP EnumSurfaces(THIS_ DWORD, LPDDSURFACEDESC2, LPVOID,LPDDENUMSURFACESCALLBACK2 ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP FlipToGDISurface(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetCaps( THIS_ LPDDCAPS first, LPDDCAPS second) 
	{  
		LOG(__FUNCTION__"---PIZDEC"); 
		glp_DirectDraw4->GetCaps(first, second);
		return 0; 
	};
    STDMETHODIMP GetDisplayMode( THIS_ LPDDSURFACEDESC2) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetFourCCCodes(THIS_  LPDWORD, LPDWORD ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetGDISurface(THIS_ LPDIRECTDRAWSURFACE4 FAR *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetMonitorFrequency(THIS_ LPDWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetScanLine(THIS_ LPDWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetVerticalBlankStatus(THIS_ LPBOOL ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP Initialize(THIS_ GUID FAR *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP RestoreDisplayMode(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP SetCooperativeLevel(THIS_ HWND hWnd, DWORD dwFlags) 
	{  
		LOG(__FUNCTION__);
		fprintf(log, "HWND IS: %x\n", hWnd);
		fprintf(log, "dwFlags: %04x\n", dwFlags);
		glp_DirectDraw4->SetCooperativeLevel(hWnd, dwFlags /*DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE /*DDSCL_NORMAL*/);
		return 0; 
	};
    STDMETHODIMP SetDisplayMode(
		THIS_ DWORD dwWidth, 
		DWORD dwHeight,
		DWORD dwBPP,
		DWORD dwRefreshRate,
		DWORD dwFlags )
	{  
		LOG(__FUNCTION__"---PIZDEC");
		glp_DirectDraw4->SetDisplayMode(dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);
		return 0; 
	};
    STDMETHODIMP WaitForVerticalBlank(THIS_ DWORD, HANDLE ) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    /*** Added in the v2 interface ***/
    STDMETHODIMP GetAvailableVidMem(THIS_ LPDDSCAPS2 first, LPDWORD second, LPDWORD third) 
	{  
		LOG(__FUNCTION__); 
		glp_DirectDraw4->GetAvailableVidMem(first, second, third);
		fprintf(log, 
			"dwCaps:%d\n"
			"dwCaps2:%d\n"
			"dwCaps3:%d\n"
			"dwCaps4:%d\n",
			first->dwCaps,
			first->dwCaps2,
			first->dwCaps3,
			first->dwCaps4
			);
		return 0; 
	};
    /*** Added in the V4 Interface ***/
    STDMETHODIMP GetSurfaceFromDC (THIS_ HDC, LPDIRECTDRAWSURFACE4 *) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP RestoreAllSurfaces(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP TestCooperativeLevel(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHODIMP GetDeviceIdentifier(THIS_ LPDDDEVICEIDENTIFIER dID, DWORD second) 
	{  
		HRESULT hr;
		LOG(__FUNCTION__"");
		
		hr = glp_DirectDraw4->GetDeviceIdentifier(dID, second);
		fprintf(log, 
				"dID->dwVendorId = %x\n"
				"dID->dwDeviceId = %x\n"
				"dID->dwSubSysId = %x\n"
				"dID->dwRevision = %x\n",
				dID->dwVendorId,
				dID->dwDeviceId,
				dID->dwSubSysId,
				dID->dwRevision
				);
		fflush(log);
		return hr;
	}
	LPDDENUMCALLBACK GetOrigEnumDevices()
	{
		return origCallBack;
	}
	static 
	BOOL WINAPI DDEnumCallback (  GUID FAR *lpGUID,           
		LPSTR  lpDriverDescription,   LPSTR  lpDriverName,        
		LPVOID lpContext            
	)
	{
		fprintf(
			log,
			"DriverDescription: %s\n"
			"DriverName: %s\n",
			lpDriverDescription,
			lpDriverName
		);
		LPDDENUMCALLBACK  origCallBack = glp_FakeDirectDraw4->GetOrigEnumDevices();
		HRESULT hr;
		return hr; //origCallBack();
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

		fprintf(log, "PRINT_GUID:\n%x-%x-%x-%x%x\n", riid.Data1, riid.Data2, riid.Data3, 
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
	STDMETHODIMP    CreateSurface(LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR *, IUnknown FAR *)
	{
		HRESULT hr;
		LOG(__FUNCTION__);
		return hr;
	}
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



