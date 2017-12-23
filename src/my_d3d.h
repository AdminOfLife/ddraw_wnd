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
		LPVOID tmp;
		LOG(__FUNCTION__);

		fprintf(log, "%x-%x-%x-%x%x\n", riid.Data1, riid.Data2, riid.Data3, 
			(int)((int*)riid.Data4)[0], (int)((int*)riid.Data4)[4]);
		//lpOrigDirectDraw->QueryInterface(riid, (LPVOID*)&tmp);

		LOG("BEFORE QUERY_INTERFACE");
		glp_Direct3D3->QueryInterface(riid, (LPVOID*)&tmp);
		LOG("AFTER QUERY_INTERFACE");
		if (IsEqualIID(IID_IDirect3D7, riid))
		{
			*ppvObj = lpd3d7;
			glp_Direct3D7 = LPDIRECT3D7(tmp);
			LOG("THIS IS DIRECT_3D3");
		}
		return 0; 
	};
    STDMETHOD_(ULONG,AddRef)(THIS) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD_(ULONG,Release)(THIS) {  LOG(__FUNCTION__"---"); return 0; };

    /*** IDirect3D3 methods ***/
    STDMETHOD(EnumDevices)(THIS_ LPD3DENUMDEVICESCALLBACK first,LPVOID second) 
	{  
		LOG(__FUNCTION__"---"); 
		glp_Direct3D3->EnumDevices(first, second);
		return 0; 
	};
    STDMETHOD(CreateLight)(THIS_ LPDIRECT3DLIGHT*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateMaterial)(THIS_ LPDIRECT3DMATERIAL3*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateViewport)(THIS_ LPDIRECT3DVIEWPORT3 * first,LPUNKNOWN second) 
	{  
		LOG(__FUNCTION__"---"); 
		glp_Direct3D3->CreateViewport(first, second);
		return 0; 
	};
    STDMETHOD(FindDevice)(THIS_ LPD3DFINDDEVICESEARCH,LPD3DFINDDEVICERESULT) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateDevice)(THIS_ REFCLSID cls,LPDIRECTDRAWSURFACE4 surf,LPDIRECT3DDEVICE3* dev,LPUNKNOWN unk) 
	{  
		LOG(__FUNCTION__"---"); 
		glp_Direct3D3->CreateDevice(cls, surf, dev, unk);
		return 0; 
	};
    STDMETHOD(CreateVertexBuffer)(THIS_ LPD3DVERTEXBUFFERDESC,LPDIRECT3DVERTEXBUFFER*,DWORD,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(EnumZBufferFormats)(THIS_ REFCLSID first,LPD3DENUMPIXELFORMATSCALLBACK second,LPVOID third) 
	{  
		LOG(__FUNCTION__"---"); 
		glp_Direct3D3->EnumZBufferFormats(first, second, third);
		return 0; 
	};
    STDMETHOD(EvictManagedTextures)(THIS) {  LOG(__FUNCTION__"---"); return 0; };
};
