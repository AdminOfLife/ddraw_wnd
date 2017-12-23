#include <d3d.h>


class FakeDirect3D7: public IDirect3D7
{
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
    STDMETHOD(EnumZBufferFormats)(THIS_ REFCLSID, LPD3DENUMPIXELFORMATSCALLBACK,LPVOID) PURE;
    STDMETHOD(EvictManagedTextures)(THIS) PURE;
};

