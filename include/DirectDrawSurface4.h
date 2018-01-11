#include "common.h"
#include "DirectDrawSurface.h"

class FakeDirectDrawSurface4: public IDirectDrawSurface4
{
private:
	LPDIRECTDRAWSURFACE lpOrigDDS;
public:
	FakeDirectDrawSurface4()
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);
	}
	/*** IUnknown methods ***/
    STDMETHODIMP QueryInterface(THIS_ REFIID riid, LPVOID FAR * ppvObj)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);
		
		PrintGUID(riid);
		
		hr = glp_DirectDrawSurface4->QueryInterface(riid, (LPVOID*)&glp_DirectDrawSurface);
		if (IsEqualIID(IID_IDirectDrawSurface, riid))
		{
			*ppvObj = new FakeDirectDrawSurface();
			LOG("THIS IS DirectDrawSurface");
		}

		
		return hr;
	}
    STDMETHOD_(ULONG,AddRef) (THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		return hr;
	}
    STDMETHOD_(ULONG,Release) (THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);
		
		hr = glp_DirectDrawSurface4->Release();
		return hr;
	}
    /*** IDirectDrawSurface methods ***/
    STDMETHODIMP AddAttachedSurface(THIS_ LPDIRECTDRAWSURFACE4)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->AddAttachedSurface( );
		return hr;
	}
    STDMETHODIMP AddOverlayDirtyRect(THIS_ LPRECT)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->AddOverlayDirtyRect( );
		return hr;
	}
    STDMETHODIMP Blt(
	  LPRECT lpDestRect,                    
	  LPDIRECTDRAWSURFACE4 lpDDSrcSurface,  
	  LPRECT lpSrcRect,                     
	  DWORD dwFlags,                        
	  LPDDBLTFX lpDDBltFx                   
	)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface4->Blt(lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx);
		return hr;
	}
    STDMETHODIMP BltBatch(THIS_ LPDDBLTBATCH, DWORD, DWORD )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->BltBatch( );
		return hr;
	}
    STDMETHODIMP BltFast(THIS_ DWORD,DWORD,LPDIRECTDRAWSURFACE4, LPRECT,DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->BltFast( );
		return hr;
	}
    STDMETHODIMP DeleteAttachedSurface(THIS_ DWORD,LPDIRECTDRAWSURFACE4)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->DeleteAttachedSurface( );
		return hr;
	}
    STDMETHODIMP EnumAttachedSurfaces(THIS_ LPVOID,LPDDENUMSURFACESCALLBACK2)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->EnumAttachedSurfaces( );
		return hr;
	}
    STDMETHODIMP EnumOverlayZOrders(THIS_ DWORD,LPVOID,LPDDENUMSURFACESCALLBACK2)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->EnumOverlayZOrders( );
		return hr;
	}
    STDMETHODIMP Flip(THIS_ LPDIRECTDRAWSURFACE4, DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->Flip( );
		return hr;
	}
    STDMETHODIMP GetAttachedSurface(THIS_ LPDDSCAPS2, LPDIRECTDRAWSURFACE4 FAR *)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetAttachedSurface( );
		return hr;
	}
    STDMETHODIMP GetBltStatus(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetBltStatus( );
		return hr;
	}
    STDMETHODIMP GetCaps(THIS_ LPDDSCAPS2)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetCaps( );
		return hr;
	}
    STDMETHODIMP GetClipper(THIS_ LPDIRECTDRAWCLIPPER FAR*)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetClipper( );
		return hr;
	}
    STDMETHODIMP GetColorKey(THIS_ DWORD, LPDDCOLORKEY)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetColorKey( );
		return hr;
	}
    STDMETHODIMP GetDC(THIS_ HDC FAR *)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetDC( );
		return hr;
	}
    STDMETHODIMP GetFlipStatus(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetFlipStatus( );
		return hr;
	}
    STDMETHODIMP GetOverlayPosition(THIS_ LPLONG, LPLONG )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetOverlayPosition( );
		return hr;
	}
    STDMETHODIMP GetPalette(THIS_ LPDIRECTDRAWPALETTE FAR*)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetPalette( );
		return hr;
	}
    STDMETHODIMP GetPixelFormat(THIS_ LPDDPIXELFORMAT)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetPixelFormat( );
		return hr;
	}
    STDMETHODIMP GetSurfaceDesc(
		LPDDSURFACEDESC2 lpDDSurfaceDesc  
	)

	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface4->GetSurfaceDesc(lpDDSurfaceDesc);
		return hr;
	}
    STDMETHODIMP Initialize(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC2)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->Initialize( );
		return hr;
	}
    STDMETHODIMP IsLost(THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->IsLost( );
		return hr;
	}
    STDMETHODIMP Lock(
	  LPRECT lpDestRect,                
	  LPDDSURFACEDESC2 lpDDSurfaceDesc,  
	  DWORD dwFlags,                    
	  HANDLE hEvent                     
	)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface4->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);
		return hr;
	}
    STDMETHODIMP ReleaseDC(THIS_ HDC)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->ReleaseDC( );
		return hr;
	}
    STDMETHODIMP Restore(THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->Restore( );
		return hr;
	}
    STDMETHODIMP SetClipper(
		LPDIRECTDRAWCLIPPER lpDDClipper  
	)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface4->SetClipper(lpDDClipper);
		return hr;
	}
    STDMETHODIMP SetColorKey(THIS_ DWORD, LPDDCOLORKEY)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->SetColorKey( );
		return hr;
	}
    STDMETHODIMP SetOverlayPosition(THIS_ LONG, LONG )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->SetOverlayPosition( );
		return hr;
	}
    STDMETHODIMP SetPalette(THIS_ LPDIRECTDRAWPALETTE)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->SetPalette( );
		return hr;
	}
    STDMETHODIMP Unlock(THIS_ LPRECT)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->Unlock( );
		return hr;
	}
    STDMETHODIMP UpdateOverlay(THIS_ LPRECT, LPDIRECTDRAWSURFACE4,LPRECT,DWORD, LPDDOVERLAYFX)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->UpdateOverlay( );
		return hr;
	}
    STDMETHODIMP UpdateOverlayDisplay(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->UpdateOverlayDisplay( );
		return hr;
	}
    STDMETHODIMP UpdateOverlayZOrder(THIS_ DWORD, LPDIRECTDRAWSURFACE4)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->UpdateOverlayZOrder( );
		return hr;
	}
    /*** Added in the v2 interface ***/
    STDMETHODIMP GetDDInterface(THIS_ LPVOID FAR *)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetDDInterface( );
		return hr;
	}
    STDMETHODIMP PageLock(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->PageLock( );
		return hr;
	}
    STDMETHODIMP PageUnlock(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->PageUnlock( );
		return hr;
	}
    /*** Added in the v3 interface ***/
    STDMETHODIMP SetSurfaceDesc(THIS_ LPDDSURFACEDESC2, DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->SetSurfaceDesc( );
		return hr;
	}
    /*** Added in the v4 interface ***/
    STDMETHODIMP SetPrivateData(THIS_ REFGUID, LPVOID, DWORD, DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->SetPrivateData( );
		return hr;
	}
    STDMETHODIMP GetPrivateData(THIS_ REFGUID, LPVOID, LPDWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetPrivateData( );
		return hr;
	}
    STDMETHODIMP FreePrivateData(THIS_ REFGUID)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->FreePrivateData( );
		return hr;
	}
    STDMETHODIMP GetUniquenessValue(THIS_ LPDWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->GetUniquenessValue( );
		return hr;
	}
    STDMETHODIMP ChangeUniquenessValue(THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface4->ChangeUniquenessValue( );
		return hr;
	}
};