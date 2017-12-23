#pragma once
#include <d3d.h>
#include "common.h"




class FakeDirect3D7: public IDirect3D7
{
public:
	FakeDirect3D7()
	{
		LOG(__FUNCTION__"---PIZDEC");
	}
	/*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHOD_(ULONG,AddRef)(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHOD_(ULONG,Release)(THIS) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };

    /*** IDirect3D7 methods ***/
    STDMETHOD(EnumDevices)(THIS_ LPD3DENUMDEVICESCALLBACK7,LPVOID) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHOD(CreateDevice)(THIS_ REFCLSID,LPDIRECTDRAWSURFACE7,LPDIRECT3DDEVICE7*) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHOD(CreateVertexBuffer)(THIS_ LPD3DVERTEXBUFFERDESC,LPDIRECT3DVERTEXBUFFER7*,DWORD) {  LOG(__FUNCTION__"---PIZDEC"); return 0; };
    STDMETHOD(EnumZBufferFormats)(THIS_ REFCLSID, LPD3DENUMPIXELFORMATSCALLBACK,LPVOID) ;
    STDMETHOD(EvictManagedTextures)(THIS) ;
};


class FakeDirect3D3: public IDirect3D3
{
private:
	LPDIRECT3D7 lpd3d7;
public:
	void FakeDirect3d3()
	{
		LOG(__FUNCTION__);
		lpd3d7 = new FakeDirect3D7();
	}
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj) 
	{  		
		LOG(__FUNCTION__"");
		*ppvObj = lpd3d7;
		fprintf(log, "%x-%x-%x-%x%x\n", riid.Data1, riid.Data2, riid.Data3, 
			(int)((int*)riid.Data4)[0], (int)((int*)riid.Data4)[4]);
		//lpOrigDirectDraw4->QueryInterface(riid, (LPVOID*)&lpd3d3);
		return 0; 
	};
    STDMETHOD_(ULONG,AddRef)(THIS) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD_(ULONG,Release)(THIS) {  LOG(__FUNCTION__"---"); return 0; };

    /*** IDirect3D3 methods ***/
    STDMETHOD(EnumDevices)(THIS_ LPD3DENUMDEVICESCALLBACK,LPVOID) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateLight)(THIS_ LPDIRECT3DLIGHT*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateMaterial)(THIS_ LPDIRECT3DMATERIAL3*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateViewport)(THIS_ LPDIRECT3DVIEWPORT3*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(FindDevice)(THIS_ LPD3DFINDDEVICESEARCH,LPD3DFINDDEVICERESULT) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateDevice)(THIS_ REFCLSID,LPDIRECTDRAWSURFACE4,LPDIRECT3DDEVICE3*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateVertexBuffer)(THIS_ LPD3DVERTEXBUFFERDESC,LPDIRECT3DVERTEXBUFFER*,DWORD,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(EnumZBufferFormats)(THIS_ REFCLSID,LPD3DENUMPIXELFORMATSCALLBACK,LPVOID) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(EvictManagedTextures)(THIS) {  LOG(__FUNCTION__"---"); return 0; };
};
