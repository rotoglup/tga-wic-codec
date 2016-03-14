#include "stdafx.hpp"
#include "wicx/regman.hpp"
#include "wicx/classfactory.hpp"
#include "tgax/tgadecoder.hpp"

#include <shlobj.h>

STDAPI DllRegisterServer()
{    
	wicx::RegMan regMan;
	HRESULT result = tgax::TGA_Decoder::Register( regMan );
	if (!SUCCEEDED(result)) return result;

	// Update the Thumbnail Cache When Installing
	SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);

	return S_OK;
}

STDAPI DllUnregisterServer()
{    
	wicx::RegMan regMan;
	tgax::TGA_Decoder::Register( regMan );
	regMan.Unregister();

	return S_OK;
}

STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, void **ppv )
{    
	HRESULT result = E_INVALIDARG; 

	if ( NULL != ppv )
	{
		IClassFactory *classFactory = NULL;

		if ( CLSID_TGA_Decoder == rclsid )
		{
			result = S_OK;
			classFactory = new wicx::ClassFactory<tgax::TGA_Decoder>();
		}
		else
			result = E_NOINTERFACE;

		if ( SUCCEEDED( result ))
		{
			if ( NULL != classFactory )
				result = classFactory->QueryInterface( riid, ppv );
			else
				result = E_OUTOFMEMORY;
		}
	}

	return result;
}

BOOL APIENTRY DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )
{
	UNREFERENCED_PARAMETER( lpvReserved );

	switch ( fdwReason )
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls( hinstDLL );
			break;

		case DLL_PROCESS_DETACH:
			break;
	}

	return TRUE;
}
