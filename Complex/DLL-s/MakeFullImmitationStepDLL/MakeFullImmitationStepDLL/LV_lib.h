#pragma once
#include "LabVIEWData.h"
#include "internal_errors.h"

#ifdef  TEST_MODE_TRUE
#include <iostream>
#include <fstream>
extern std::ofstream logger;
#endif //  TEST

typedef void(*MainSCFunction) (	ArrayOfMessagesHdl, //verifier2scenariousControlOutMsgs  
								ArrayOfMessagesHdl, //scenarios2AlgOutputMsgs
								ArrayOfMessagesHdl, //scenarios2VirtPlantOutputMsgs
								ArrayOfMessagesHdl, //scenarios2VerifierOutputMsgs
								ArrayOfStatesHdl );

typedef void(*MainVPFunction) ( PortsHdl, //algOutputPorts
								PortsHdl, //algInputPorts
								ArrayOfMessagesHdl, //scenarios2VirtPlantOutputMsgs
								ArrayOfMessagesHdl, //virtualPlant2GUIOutputMsgs
								ArrayOfStatesHdl);

typedef void(*MainCAFunction) ( PortsHdl, //algInputPorts 
								PortsHdl, //algOutputPorts
								ArrayOfMessagesHdl, //scenarios2AlgOutputMsgs
								ArrayOfMessagesHdl, //algOutputMsgs
								ArrayOfStatesHdl);


typedef void(*MainVBFunction) ( PortsHdl, //algInputPorts 
								PortsHdl, //algOutputPorts
								ArrayOfMessagesHdl, //scenarios2VerifierOutputMsgs
								ArrayOfMessagesHdl, //algOutputMsgs
								ArrayOfMessagesHdl, //verifier2GUIOutputMsgs
								ArrayOfMessagesHdl, //verifier2scenariousControlOutMsgs
								ArrayOfStatesHdl);
#ifdef _WIN32

extern LPCSTR MainFunctionName;


template
<typename FunctionType>
struct ModuleDescriptor
{
	HINSTANCE module;
	LPTSTR libName;
	FunctionType mainFunction;
};

extern ModuleDescriptor <MainCAFunction> ca_module;
extern ModuleDescriptor <MainVPFunction> vp_module;
extern ModuleDescriptor <MainVBFunction> vm_module;
extern ModuleDescriptor <MainSCFunction> sc_module;

LPSTR newPathName(LStrHandle path, char * name);

template <typename MainFunctionType>
DllCallErroros freeModule(ModuleDescriptor<MainFunctionType> & descriptor)
{
	::FreeLibrary(descriptor.module);
	descriptor.mainFunction = nullptr;
	descriptor.module = nullptr; 
	return  DllCallErroros::NoError;
}


template <typename MainFunctionType>
DllCallErroros reloadModule(ModuleDescriptor<MainFunctionType> & descriptor)
{
	HINSTANCE & currLib = descriptor.module;
	const LPTSTR lib_name = descriptor.libName;
	MainFunctionType & main_function = descriptor.mainFunction;

//#ifdef TEST_MODE_TRUE
//	if (logger.is_open()) logger << "\n\t::FreeLibrary()" << lib_name << std::endl;
//#endif // TEST_MODE_TRUE
//
//	::FreeLibrary(currLib);

#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "=n\t::LoadLibrary()\n" << std::endl;
#endif // TEST_MODE_TRUE


	if (nullptr == (currLib = ::LoadLibrary(lib_name)))
	{
#ifdef TEST_MODE_TRUE
		char result[MAX_PATH];
		GetModuleFileName(NULL, result, MAX_PATH);
		if (logger.is_open()) logger << "\tERROR: LoadLibrary(lib_name)" << lib_name << ": ERROR " << GetLastError() << result << " \n" << std::endl;
#endif
		return (lastError = DllCallErroros::LoadLibError);
	}

	if (nullptr == (main_function = (MainFunctionType)::GetProcAddress((HMODULE)currLib, MainFunctionName)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR:  GetProcAdressError(): " << MainFunctionName << GetLastError() << std::endl;
#endif
		return (lastError = DllCallErroros::GetProcAdressError);
	}
	/*END  initialisation*/
	return lastError;

}

#endif





