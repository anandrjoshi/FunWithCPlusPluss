// dllmain.h : Declaration of module class.

class CHelloWorldATLModule : public ATL::CAtlDllModuleT< CHelloWorldATLModule >
{
public :
	DECLARE_LIBID(LIBID_HelloWorldATLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HELLOWORLDATL, "{C957AAE6-BF2D-4519-B4DB-897111EB7BDD}")
};

extern class CHelloWorldATLModule _AtlModule;
