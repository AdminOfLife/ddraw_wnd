#pragma once


#include "common.h"
//typedef HRESULT (CALLBACK * LPD3DENUMDEVICESCALLBACK)(GUID FAR *lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName, LPD3DDEVICEDESC, LPD3DDEVICEDESC, LPVOID);






class FakeDirect3DDevice3: public IDirect3DDevice3
{

private:
	typedef struct _D3DRENDERSTATETYPE_STR {
			D3DRENDERSTATETYPE dwRenderStateType;
			LPSTR strRenderStateType;
		}_renderstate;
	_renderstate *renderstate;
public:
	FakeDirect3DDevice3()
	{
		
		static struct _D3DRENDERSTATETYPE_STR {
			D3DRENDERSTATETYPE dwRenderStateType;
			LPSTR strRenderStateType;
		}D3DRENDERSTATETYPE_STR[] = {
			D3DRENDERSTATE_TEXTUREHANDLE      ,   "D3DRENDERSTATE_TEXTUREHANDLE",
			D3DRENDERSTATE_ANTIALIAS          ,   "D3DRENDERSTATE_ANTIALIAS",
			D3DRENDERSTATE_TEXTUREADDRESS     ,   "D3DRENDERSTATE_TEXTUREADDRESS",
			D3DRENDERSTATE_TEXTUREPERSPECTIVE ,   "D3DRENDERSTATE_TEXTUREPERSPECTIVE",
			D3DRENDERSTATE_WRAPU              ,   "D3DRENDERSTATE_WRAPU",
			D3DRENDERSTATE_WRAPV              ,   "D3DRENDERSTATE_WRAPV",
			D3DRENDERSTATE_ZENABLE            ,   "D3DRENDERSTATE_ZENABLE",
			D3DRENDERSTATE_FILLMODE           ,   "D3DRENDERSTATE_FILLMODE",
			D3DRENDERSTATE_SHADEMODE          ,   "D3DRENDERSTATE_SHADEMODE",
			D3DRENDERSTATE_LINEPATTERN        ,   "D3DRENDERSTATE_LINEPATTERN",
			D3DRENDERSTATE_MONOENABLE         ,   "D3DRENDERSTATE_MONOENABLE",
			D3DRENDERSTATE_ROP2               ,   "D3DRENDERSTATE_ROP2",
			D3DRENDERSTATE_PLANEMASK          ,   "D3DRENDERSTATE_PLANEMASK",
			D3DRENDERSTATE_ZWRITEENABLE       ,   "D3DRENDERSTATE_ZWRITEENABLE",
			D3DRENDERSTATE_ALPHATESTENABLE    ,   "D3DRENDERSTATE_ALPHATESTENABLE",
			D3DRENDERSTATE_LASTPIXEL          ,   "D3DRENDERSTATE_LASTPIXEL",
			D3DRENDERSTATE_TEXTUREMAG         ,   "D3DRENDERSTATE_TEXTUREMAG",
			D3DRENDERSTATE_TEXTUREMIN         ,   "D3DRENDERSTATE_TEXTUREMIN",
			D3DRENDERSTATE_SRCBLEND           ,   "D3DRENDERSTATE_SRCBLEND",
			D3DRENDERSTATE_DESTBLEND          ,   "D3DRENDERSTATE_DESTBLEND",
			D3DRENDERSTATE_TEXTUREMAPBLEND    ,   "D3DRENDERSTATE_TEXTUREMAPBLEND",
			D3DRENDERSTATE_CULLMODE           ,   "D3DRENDERSTATE_CULLMODE",
			D3DRENDERSTATE_ZFUNC              ,   "D3DRENDERSTATE_ZFUNC",
			D3DRENDERSTATE_ALPHAREF           ,   "D3DRENDERSTATE_ALPHAREF",
			D3DRENDERSTATE_ALPHAFUNC          ,   "D3DRENDERSTATE_ALPHAFUNC",
			D3DRENDERSTATE_DITHERENABLE       ,   "D3DRENDERSTATE_DITHERENABLE",
			D3DRENDERSTATE_ALPHABLENDENABLE   ,   "D3DRENDERSTATE_ALPHABLENDENABLE",
			D3DRENDERSTATE_FOGENABLE          ,   "D3DRENDERSTATE_FOGENABLE",
			D3DRENDERSTATE_SPECULARENABLE     ,   "D3DRENDERSTATE_SPECULARENABLE",
			D3DRENDERSTATE_ZVISIBLE           ,   "D3DRENDERSTATE_ZVISIBLE",
			D3DRENDERSTATE_SUBPIXEL           ,   "D3DRENDERSTATE_SUBPIXEL",
			D3DRENDERSTATE_SUBPIXELX          ,   "D3DRENDERSTATE_SUBPIXELX",
			D3DRENDERSTATE_STIPPLEDALPHA      ,   "D3DRENDERSTATE_STIPPLEDALPHA",
			D3DRENDERSTATE_FOGCOLOR           ,   "D3DRENDERSTATE_FOGCOLOR",
			D3DRENDERSTATE_FOGTABLEMODE       ,   "D3DRENDERSTATE_FOGTABLEMODE",
			D3DRENDERSTATE_FOGTABLESTART      ,   "D3DRENDERSTATE_FOGTABLESTART",
			D3DRENDERSTATE_FOGTABLEEND        ,   "D3DRENDERSTATE_FOGTABLEEND",
			D3DRENDERSTATE_FOGTABLEDENSITY    ,   "D3DRENDERSTATE_FOGTABLEDENSITY",
			D3DRENDERSTATE_STIPPLEENABLE      ,   "D3DRENDERSTATE_STIPPLEENABLE",
			D3DRENDERSTATE_EDGEANTIALIAS      ,   "D3DRENDERSTATE_EDGEANTIALIAS",
			D3DRENDERSTATE_COLORKEYENABLE     ,   "D3DRENDERSTATE_COLORKEYENABLE",
			D3DRENDERSTATE_BORDERCOLOR        ,   "D3DRENDERSTATE_BORDERCOLOR",
			D3DRENDERSTATE_TEXTUREADDRESSU    ,   "D3DRENDERSTATE_TEXTUREADDRESSU",
			D3DRENDERSTATE_TEXTUREADDRESSV    ,   "D3DRENDERSTATE_TEXTUREADDRESSV",
			D3DRENDERSTATE_MIPMAPLODBIAS      ,   "D3DRENDERSTATE_MIPMAPLODBIAS",
			D3DRENDERSTATE_ZBIAS              ,   "D3DRENDERSTATE_ZBIAS",
			D3DRENDERSTATE_RANGEFOGENABLE     ,   "D3DRENDERSTATE_RANGEFOGENABLE",
			D3DRENDERSTATE_ANISOTROPY         ,   "D3DRENDERSTATE_ANISOTROPY",
			D3DRENDERSTATE_FLUSHBATCH         ,   "D3DRENDERSTATE_FLUSHBATCH",
			D3DRENDERSTATE_TRANSLUCENTSORTINDEPENDENT, "D3DRENDERSTATE_TRANSLUCENTSORTINDEPENDENT",
			D3DRENDERSTATE_STENCILENABLE      ,   "D3DRENDERSTATE_STENCILENABLE",
			D3DRENDERSTATE_STENCILFAIL        ,   "D3DRENDERSTATE_STENCILFAIL",
			D3DRENDERSTATE_STENCILZFAIL       ,   "D3DRENDERSTATE_STENCILZFAIL",
			D3DRENDERSTATE_STENCILPASS        ,   "D3DRENDERSTATE_STENCILPASS",
			D3DRENDERSTATE_STENCILFUNC        ,   "D3DRENDERSTATE_STENCILFUNC",
			D3DRENDERSTATE_STENCILREF         ,   "D3DRENDERSTATE_STENCILREF",
			D3DRENDERSTATE_STENCILMASK        ,   "D3DRENDERSTATE_STENCILMASK",
			D3DRENDERSTATE_STENCILWRITEMASK   ,   "D3DRENDERSTATE_STENCILWRITEMASK",
			D3DRENDERSTATE_TEXTUREFACTOR      ,   "D3DRENDERSTATE_TEXTUREFACTOR",
			D3DRENDERSTATE_STIPPLEPATTERN00   ,   "D3DRENDERSTATE_STIPPLEPATTERN00",
		       
			D3DRENDERSTATE_STIPPLEPATTERN31   ,   "D3DRENDERSTATE_STIPPLEPATTERN31",
			D3DRENDERSTATE_WRAP0              ,   "D3DRENDERSTATE_WRAP0",
		       
			D3DRENDERSTATE_WRAP7              ,   "D3DRENDERSTATE_WRAP7",
			D3DRENDERSTATE_FORCE_DWORD        ,   "D3DRENDERSTATE_FORCE_DWORD"
		};
		renderstate = reinterpret_cast<_renderstate*>(&D3DRENDERSTATETYPE_STR[0]);
	}

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)( REFIID riid, LPVOID * ppvObj) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD_(ULONG,AddRef)() 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD_(ULONG,Release)() 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);
		hr = glp_Direct3DDeviece3->Release();
		
		return hr;
	}

    /*** IDirect3DDevice3 methods ***/
    STDMETHOD(GetCaps)(
	  LPD3DDEVICEDESC lpD3DHWDevDesc,  
	  LPD3DDEVICEDESC lpD3DHELDevDesc
	  )
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->GetCaps(lpD3DHWDevDesc, lpD3DHELDevDesc);
		return hr;
	}
    STDMETHOD(GetStats)( LPD3DSTATS lpD3DStats ) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(AddViewport)( LPDIRECT3DVIEWPORT3 lpDirect3DViewport ) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->AddViewport(lpDirect3DViewport);
		return hr;
	}
    STDMETHOD(DeleteViewport)( LPDIRECT3DVIEWPORT3) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(NextViewport)( LPDIRECT3DVIEWPORT3,LPDIRECT3DVIEWPORT3*,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(EnumTextureFormats)(
		LPD3DENUMPIXELFORMATSCALLBACK lpd3dEnumPixelProc,  
		LPVOID lpArg                                           
		) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		
		return glp_Direct3DDeviece3->EnumTextureFormats(lpd3dEnumPixelProc, lpArg);
	}
    STDMETHOD(BeginScene)() 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->BeginScene();
		return hr;
	}
    STDMETHOD(EndScene)() 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->EndScene();
		return hr;
	}
    STDMETHOD(GetDirect3D)( LPDIRECT3D3*) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetCurrentViewport)( LPDIRECT3DVIEWPORT3 lpd3dViewport) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->SetCurrentViewport(lpd3dViewport);
		return hr;
	}
    STDMETHOD(GetCurrentViewport)( LPDIRECT3DVIEWPORT3 *) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetRenderTarget)( LPDIRECTDRAWSURFACE4,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(GetRenderTarget)( LPDIRECTDRAWSURFACE4 *) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(Begin)( D3DPRIMITIVETYPE,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(BeginIndexed)( D3DPRIMITIVETYPE,DWORD,LPVOID,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(Vertex)( LPVOID) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(Index)( WORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(End)( DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(GetRenderState)( D3DRENDERSTATETYPE,LPDWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetRenderState)(
		D3DRENDERSTATETYPE dwRenderStateType,  
		DWORD dwRenderState                    
	)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		
		fprintf(log, "\t***%s***\n", GetRenderTypeStr(dwRenderStateType));
		hr = glp_Direct3DDeviece3->SetRenderState(dwRenderStateType, dwRenderState);
		return hr;
	}
    STDMETHOD(GetLightState)( D3DLIGHTSTATETYPE,LPDWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetLightState)(
	  D3DLIGHTSTATETYPE dwLightStateType,  
	  DWORD dwLightState                   
		) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->SetLightState(dwLightStateType, dwLightState);
		return hr;
	}
    STDMETHOD(SetTransform)( D3DTRANSFORMSTATETYPE,LPD3DMATRIX) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(GetTransform)( D3DTRANSFORMSTATETYPE,LPD3DMATRIX) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(MultiplyTransform)( D3DTRANSFORMSTATETYPE,LPD3DMATRIX) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(DrawPrimitive)(
	  D3DPRIMITIVETYPE dptPrimitiveType,  
	  DWORD  dwVertexTypeDesc,            
	  LPVOID lpvVertices,                 
	  DWORD  dwVertexCount,               
	  DWORD  dwFlags                      
		)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->DrawPrimitive(dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags);
		return hr;
	}
    STDMETHOD(DrawIndexedPrimitive)( D3DPRIMITIVETYPE,DWORD,LPVOID,DWORD,LPWORD,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetClipStatus)( LPD3DCLIPSTATUS) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(GetClipStatus)( LPD3DCLIPSTATUS) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(DrawPrimitiveStrided)( D3DPRIMITIVETYPE,DWORD,LPD3DDRAWPRIMITIVESTRIDEDDATA,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(DrawIndexedPrimitiveStrided)( D3DPRIMITIVETYPE,DWORD,LPD3DDRAWPRIMITIVESTRIDEDDATA,DWORD,LPWORD,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(DrawPrimitiveVB)( D3DPRIMITIVETYPE,LPDIRECT3DVERTEXBUFFER,DWORD,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(DrawIndexedPrimitiveVB)( D3DPRIMITIVETYPE,LPDIRECT3DVERTEXBUFFER,LPWORD,DWORD,DWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(ComputeSphereVisibility)( LPD3DVECTOR,LPD3DVALUE,DWORD,DWORD,LPDWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(GetTexture)( DWORD,LPDIRECT3DTEXTURE2 *) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetTexture)( 
		DWORD dwStage,
		LPDIRECT3DTEXTURE2 lpTexture
		)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->SetTexture(dwStage, lpTexture);
		return hr;
	}
    STDMETHOD(GetTextureStageState)( DWORD,D3DTEXTURESTAGESTATETYPE,LPDWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}
    STDMETHOD(SetTextureStageState)( 
		DWORD dwStage,
		D3DTEXTURESTAGESTATETYPE dwState,
		DWORD dwValue
		)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		hr = glp_Direct3DDeviece3->SetTextureStageState(dwStage, dwState, dwValue);
		return hr;
	}
    STDMETHOD(ValidateDevice)( LPDWORD) 
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		
		return hr;
	}

	LPSTR GetRenderTypeStr(D3DRENDERSTATETYPE type)
	{
		HRESULT hr = 0;
		LOG(__FUNCTION__);

		for (int i = 0; renderstate[i].dwRenderStateType != D3DRENDERSTATE_FORCE_DWORD; i++)
		{
			if (renderstate[i].dwRenderStateType == type)
				return renderstate[i].strRenderStateType;
		}
		return NULL;
	}
};



class FakeDirect3D7: public IDirect3D7
{
private:
public:
	FakeDirect3D7()
	{
		LOG(__FUNCTION__);
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
	//LPDIRECT3D7 lpd3d7;
	LPD3DENUMDEVICESCALLBACK origCallBack;
	LPDIRECT3DDEVICE3 lpD3DDevice3;
public:
	FakeDirect3D3()
	{
		LOG(__FUNCTION__);
		//MessageBox(NULL, "Test", "Caption", MB_OK);
		//lpd3d7 = new FakeDirect3D7();
		lpD3DDevice3 = new FakeDirect3DDevice3();
	}
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj) 
	{  		
		LPVOID tmp;
		LOG(__FUNCTION__);

		PrintGUID(riid);
		//lpOrigDirectDraw->QueryInterface(riid, (LPVOID*)&tmp);

		LOG("BEFORE QUERY_INTERFACE");
		glp_Direct3D3->QueryInterface(riid, (LPVOID*)&tmp);
		LOG("AFTER QUERY_INTERFACE");
		//if (IsEqualIID(IID_IDirect3D7, riid))
		//{
		//	//*ppvObj = lpd3d7;
		//	//glp_Direct3D7 = LPDIRECT3D7(tmp);
		//	//LOG("THIS IS DIRECT_3D3");
		//}
		//else if (IsEqualIID(IID_IDirect3D3, riid))
		//{
		//	//*ppvObj = lpd3d7;
		//	glp_Direct3D7 = LPDIRECT3D7(tmp);
		//	LOG("THIS IS DIRECT_3D3");
		//}
		return 0; 
	};
    STDMETHOD_(ULONG,AddRef)(THIS) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD_(ULONG,Release)(THIS) 
	{
		LOG(__FUNCTION__"---"); 
		
		return glp_Direct3D3->Release();
	};

    /*** IDirect3D3 methods ***/
    STDMETHOD(EnumDevices)(THIS_ LPD3DENUMDEVICESCALLBACK first,LPVOID second) 
	{  
		LOG(__FUNCTION__"---");
		//typedef HRESULT (FAR PASCAL * LPD3DENUMDEVICESCALLBACK)
		//(LPGUID lpGuid,                     
		//LPSTR lpDeviceDescription,          
		//LPSTR lpDeviceName,                 
		//LPD3DDEVICEDESC lpD3DHWDeviceDesc,  
		//LPD3DDEVICEDESC lpD3DHELD9eviceDesc,  
		//LPVOID lpUserArg                    
		//);

		origCallBack = first;
		glp_Direct3D3->EnumDevices(enumDevicesCallBack, second);
		return 0; 
	};
    STDMETHOD(CreateLight)(THIS_ LPDIRECT3DLIGHT*,LPUNKNOWN) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateMaterial)(
		LPDIRECT3DMATERIAL3* lplpDirect3DMaterial,  
		IUnknown* pUnkOuter                         
	)
	{  
		LOG(__FUNCTION__); 
		glp_Direct3D3->CreateMaterial(lplpDirect3DMaterial, pUnkOuter);
		return 0; 
	};
    STDMETHOD(CreateViewport)(
		LPDIRECT3DVIEWPORT3* lplpD3DViewport,  
		IUnknown* pUnkOuter                     
		) 
	{  
		LOG(__FUNCTION__"---"); 
		
		return glp_Direct3D3->CreateViewport(lplpD3DViewport, pUnkOuter);
	};
    STDMETHOD(FindDevice)(THIS_ LPD3DFINDDEVICESEARCH,LPD3DFINDDEVICERESULT) {  LOG(__FUNCTION__"---"); return 0; };
    STDMETHOD(CreateDevice)(THIS_ REFCLSID cls,LPDIRECTDRAWSURFACE4 surf,LPDIRECT3DDEVICE3* dev,LPUNKNOWN unk) 
	{  
		//LPDIRECT3DDEVICE3 lpD3DDevice;
		HRESULT hr = 0;
		LOG(__FUNCTION__"---");
		PrintGUID(cls);
		hr = glp_Direct3D3->CreateDevice(cls, surf, &glp_Direct3DDeviece3, unk);
		if (FAILED(hr))
		{
			LOG("Create device failed!");
		}
		else
		{
			LOG("Create device succeed! Yes?");
			*dev = lpD3DDevice3;
		}
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
	LPD3DENUMDEVICESCALLBACK GetOrigEnumDevices()
	{
		return origCallBack;
	}

	static HRESULT FAR PASCAL enumDevicesCallBack(
		GUID FAR* lpGuid,                    
		LPSTR lpDeviceDescription,           
		LPSTR lpDeviceName,                  
		LPD3DDEVICEDESC lpD3DHWDeviceDesc,   
		LPD3DDEVICEDESC lpD3DHELDeviceDesc,  
		LPVOID lpContext                     
	)
	{
		fprintf(
			log,
			"device desc: %s\n"
			"DeviceName: %s\n",
			lpDeviceDescription,
			lpDeviceName
		);
		LPD3DENUMDEVICESCALLBACK origCallBack = glp_FakeDirect3D3->GetOrigEnumDevices();
		HRESULT hr = 0;
		return origCallBack(
			lpGuid,                    
			lpDeviceDescription,           
			lpDeviceName,                  
			lpD3DHWDeviceDesc,   
			lpD3DHELDeviceDesc,  
			lpContext
			);
	}

};



