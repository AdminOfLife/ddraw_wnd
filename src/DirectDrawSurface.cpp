#include "DirectDrawSurface.h"

	FakeDirectDrawSurface::FakeDirectDrawSurface()
	{
		LOG(__FUNCTION__);
	}
	/*** IUnknown methods ***/
    STDMETHODIMP FakeDirectDrawSurface::QueryInterface(THIS_ REFIID riid, LPVOID FAR * ppvObj)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);
		
		PrintGUID(riid);
		hr = glp_DirectDrawSurface->QueryInterface(riid, ppvObj);
		return hr;
	}
	STDMETHODIMP_(ULONG)FakeDirectDrawSurface::AddRef (THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->AddRef( );
		return hr;
	}
	STDMETHODIMP_(ULONG)FakeDirectDrawSurface::Release (THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->Release( );
		return hr;
	}
    /*** IDirectDrawSurface methods ***/
    STDMETHODIMP FakeDirectDrawSurface::AddAttachedSurface(THIS_ LPDIRECTDRAWSURFACE)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->AddAttachedSurface( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::AddOverlayDirtyRect(THIS_ LPRECT)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->AddOverlayDirtyRect( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::Blt(THIS_ LPRECT,LPDIRECTDRAWSURFACE, LPRECT,DWORD, LPDDBLTFX)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->Blt( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::BltBatch(THIS_ LPDDBLTBATCH, DWORD, DWORD )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->BltBatch( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::BltFast(THIS_ DWORD,DWORD,LPDIRECTDRAWSURFACE, LPRECT,DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->BltFast( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::DeleteAttachedSurface(THIS_ DWORD,LPDIRECTDRAWSURFACE)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->DeleteAttachedSurface( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::EnumAttachedSurfaces(THIS_ LPVOID,LPDDENUMSURFACESCALLBACK)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->EnumAttachedSurfaces( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::EnumOverlayZOrders(THIS_ DWORD,LPVOID,LPDDENUMSURFACESCALLBACK)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->EnumOverlayZOrders( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::Flip(THIS_ LPDIRECTDRAWSURFACE, DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->Flip( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetAttachedSurface(THIS_ LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetBltStatus(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->GetBltStatus( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetCaps(THIS_ LPDDSCAPS lpDDCaps)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->GetCaps(lpDDCaps);
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetClipper(THIS_ LPDIRECTDRAWCLIPPER FAR*)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->GetClipper( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetColorKey(THIS_ DWORD, LPDDCOLORKEY)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->GetColorKey( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetDC(THIS_ HDC FAR *)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->GetDC( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetFlipStatus(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->GetFlipStatus( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetOverlayPosition(THIS_ LPLONG, LPLONG )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->GetOverlayPosition( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetPalette(THIS_ LPDIRECTDRAWPALETTE FAR* lplpDDPalette)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->GetPalette(lplpDDPalette);
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetPixelFormat(THIS_ LPDDPIXELFORMAT lpDDPixelFormat )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->GetPixelFormat(lpDDPixelFormat );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::GetSurfaceDesc(THIS_ LPDDSURFACEDESC lpDDSurfaceDesc  )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->GetSurfaceDesc(lpDDSurfaceDesc );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::Initialize(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->Initialize( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::IsLost(THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->IsLost( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::Lock(THIS_ LPRECT,LPDDSURFACEDESC,DWORD,HANDLE)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->Lock( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::ReleaseDC(THIS_ HDC hDC)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		hr = glp_DirectDrawSurface->ReleaseDC(hDC);
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::Restore(THIS)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->Restore( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::SetClipper(THIS_ LPDIRECTDRAWCLIPPER)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->SetClipper( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::SetColorKey(THIS_ DWORD, LPDDCOLORKEY)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->SetColorKey( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::SetOverlayPosition(THIS_ LONG, LONG )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->SetOverlayPosition( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::SetPalette(THIS_ LPDIRECTDRAWPALETTE)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->SetPalette( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::Unlock(THIS_ LPVOID)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->Unlock( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::UpdateOverlay(THIS_ LPRECT, LPDIRECTDRAWSURFACE,LPRECT,DWORD, LPDDOVERLAYFX)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->UpdateOverlay( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::UpdateOverlayDisplay(THIS_ DWORD)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->UpdateOverlayDisplay( );
		return hr;
	}
    STDMETHODIMP FakeDirectDrawSurface::UpdateOverlayZOrder(THIS_ DWORD, LPDIRECTDRAWSURFACE)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		//hr = glp_DirectDrawSurface->UpdateOverlayZOrder( );
		return hr;
	}