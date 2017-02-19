// HelloWorldBHO.h : Declaration of the CHelloWorldBHO

#pragma once
#include "resource.h"       // main symbols



#include "HelloWorldATL_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CHelloWorldBHO

class ATL_NO_VTABLE CHelloWorldBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHelloWorldBHO, &CLSID_HelloWorldBHO>,
	public IDispatchImpl<IHelloWorldBHO, &IID_IHelloWorldBHO, &LIBID_HelloWorldATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHelloWorldBHO()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELLOWORLDBHO)


BEGIN_COM_MAP(CHelloWorldBHO)
	COM_INTERFACE_ENTRY(IHelloWorldBHO)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(HelloWorldBHO), CHelloWorldBHO)
