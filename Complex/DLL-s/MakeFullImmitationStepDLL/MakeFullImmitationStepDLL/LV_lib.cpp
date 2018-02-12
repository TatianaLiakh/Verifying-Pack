#include "LV_lib.h"

//std::ofstream logger("save.txt");



ModuleDescriptor ca_module = { nullptr , "CA.dll" , nullptr };
ModuleDescriptor vp_module = { nullptr , "VP.dll" , nullptr };
ModuleDescriptor vb_module = { nullptr , "D:/VB.dll" , nullptr };
ModuleDescriptor sc_module = { nullptr , "SC.dll" , nullptr };


HINSTANCE hCAModule = nullptr;
HINSTANCE hVPModule = nullptr;
HINSTANCE hVBModule = nullptr;
HINSTANCE hSCModule = nullptr;

LPTSTR ControlAlgorithmName = "CA.dll";
LPTSTR VirtualBlockName = "VB.dll";
LPTSTR VirtualPlantName = "VP.dll";
LPTSTR ScriptControlName = "SC.dll";

//typedef void(__stdcall * MainFunction) ();
//typedef void(__stdcall * VP) ();
//typedef void(__stdcall * VB) ();
//typedef void(__stdcall * SC) ();

MainFunction ca = nullptr;
MainFunction vp = nullptr;
MainFunction vb = nullptr;
MainFunction sc = nullptr;
LPCSTR MainFunctionName = "LLD";

/*LV DATA STORE*/
PortsHdl algIP = nullptr;
PortsHdl algOP = nullptr;
/*MsgQueues*/
ArrayOfMessagesHdl sc2AlgOutMsgs = nullptr;
ArrayOfMessagesHdl sc2VpOutMsgs = nullptr;
ArrayOfMessagesHdl sc2VerfOutMsgs = nullptr;
ArrayOfMessagesHdl ver2scOutMsgs = nullptr;

/*Msg2GUI*/
ArrayOfMessagesHdl algOutMsgs = nullptr;
ArrayOfMessagesHdl verf2GUIOutMsgs = nullptr;
ArrayOfMessagesHdl vp2GUIOutMsgs = nullptr;
/*StatesArrays*/
ArrayOfStatesHdl aS = nullptr;
ArrayOfStatesHdl vpS = nullptr;
ArrayOfStatesHdl verS = nullptr;
ArrayOfStatesHdl scS = nullptr;



DllCallErroros setPortsArrays(HINSTANCE module, PortsHdl arrayInp, PortsHdl arrayOutp)
{
	typedef int32_t( * set_ports_func)(PortsHdl);
	set_ports_func initPortsDLLFunction = nullptr;	

	if (nullptr != (initPortsDLLFunction = (set_ports_func)::GetProcAddress((HMODULE)module, "set_input_ports_array")))
	{
		initPortsDLLFunction(arrayInp);
	}
	else return DllCallErroros::GetProcAdressError;

	if (nullptr != (initPortsDLLFunction = (set_ports_func)::GetProcAddress((HMODULE)module, "set_output_ports_array")))
	{
		initPortsDLLFunction(arrayOutp);
	}
	else return  DllCallErroros::GetProcAdressError;


	if (logger.is_open()) logger << "\tsetPortsArrays OK!" << std::endl;

	return  DllCallErroros::NoError;
}

DllCallErroros setIOMsgsArrays(HINSTANCE module, ArrayOfMessagesHdl inputMsgs, ArrayOfMessagesHdl outputMsgs)
{
	typedef int32_t( * set_msgs_array_func) (ArrayOfMessagesHdl);
	set_msgs_array_func initMsgQueueFunction = nullptr;

	if (nullptr != (initMsgQueueFunction = (set_msgs_array_func)::GetProcAddress((HMODULE)module, "set_input_msg")))
	{
		initMsgQueueFunction(inputMsgs);
	}
	else return  DllCallErroros::GetProcAdressError;

	if (nullptr != (initMsgQueueFunction = (set_msgs_array_func)::GetProcAddress((HMODULE)module, "set_output_msg")))
	{
		initMsgQueueFunction(outputMsgs);
	}
	else return  DllCallErroros::GetProcAdressError;

	if (logger.is_open()) logger << "\setIOMsgsArrays OK!" << std::endl;

	return  DllCallErroros::NoError;
}
DllCallErroros setIOMsgsArrays(HINSTANCE module, ArrayOfMessagesHdl msgs, LPCSTR functionName)
{

	//if (logger.is_open()) logger << " setIOMsgsArrays START" << std::endl;

	typedef int32_t( * set_msgs_array_func) (ArrayOfMessagesHdl);
	set_msgs_array_func initMsgQueueFunction = nullptr;

	if (nullptr != (initMsgQueueFunction = (set_msgs_array_func)::GetProcAddress((HMODULE)module, functionName)))
	{
		if (logger.is_open()) logger << "\t" << functionName << " OK!" << std::endl;
		initMsgQueueFunction(msgs);
		
		return  DllCallErroros::NoError;
	}
	else
	{
		if (logger.is_open()) logger << functionName << " BAD!" << std::endl;
		return  DllCallErroros::GetProcAdressError;
	}

	//if (logger.is_open()) logger << " setIOMsgsArrays FINISHED" << std::endl;

}

DllCallErroros setStatesArray(HINSTANCE module, ArrayOfStatesHdl states)
{
	typedef int32_t( * set_states_array_func) (ArrayOfStatesHdl);
	set_states_array_func initStatesFunction = nullptr;

	if (nullptr != (initStatesFunction = (set_states_array_func)::GetProcAddress((HMODULE)module, "set_states_array")))
	{
		initStatesFunction(states);
	}
	else return  DllCallErroros::GetProcAdressError;
	if (logger.is_open()) logger << "\tsetStatesArray OK!" << std::endl;


	return  DllCallErroros::NoError;
}


DllCallErroros reloadLibrary(ModuleDescriptor & descriptor)
{
	HINSTANCE & currLib = descriptor.module;	
	MainFunction & runFunction = descriptor.function;
	const LPTSTR lib_name = descriptor.libName; 

#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "\t::FreeLibrary()\n" << std::endl;
#endif // TEST_MODE_TRUE
	::FreeLibrary(currLib);

#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "\t::LoadLibrary()\n" << std::endl;
#endif // TEST_MODE_TRUE

	if (nullptr == (currLib = ::LoadLibrary(lib_name)))
	{
#ifdef TEST_MODE_TRUE
		char result[MAX_PATH];
		GetModuleFileName(NULL, result, MAX_PATH); 
		if (logger.is_open()) logger << "\tERROR: LoadLibrary(lib_name)" << lib_name<<": ERROR " << GetLastError()<< result<<" \n" << std::endl;
#endif
		return (lastError = DllCallErroros::LoadLibError);
	}

	if (nullptr == (runFunction = (MainFunction)::GetProcAddress((HMODULE)currLib, MainFunctionName)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR:  GetProcAdressError(): " << MainFunctionName << GetLastError() << std::endl;
#endif
		return (lastError = DllCallErroros::GetProcAdressError);
	}

}

DllCallErroros reloadCAModule()
{
#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "CA: LOAD \n" << std::endl;
#endif
	reloadLibrary(ca_module);

	/*Time to Arrays RESIZE*/

	if (DllCallErroros::NoError != (lastError = setPortsArrays(ca_module.module, algIP, algOP)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: CA: setPortsArrays()\n" << std::endl;
#endif		
		return lastError;
	}
	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(ca_module.module, sc2AlgOutMsgs, algOutMsgs)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: CA: setIOMsgsArrays()\n" << std::endl;		
#endif
		return lastError;
	}

	setStatesArray(ca_module.module, aS);

	/*END CA initialisation*/
	return lastError;
}

/*VIRTUAL PLANT*/
DllCallErroros reloadVPModule()
{
#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "VP: LOAD \n" << std::endl;
#endif
	reloadLibrary(vp_module);

	if (DllCallErroros::NoError != (lastError = setPortsArrays(vp_module.module, algOP, algIP)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: VP: setPortsArrays()\n" << std::endl;
#endif
		return lastError;

	}
	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(vp_module.module, sc2VpOutMsgs, vp2GUIOutMsgs)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: VP: setIOMsgsArrays()\n" << std::endl;
#endif
		return lastError;
	}

	setStatesArray(vp_module.module, vpS);

	return lastError;
}
DllCallErroros reloadVBModule()
{
#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "VB: LOADING STARTED \n" << std::endl;
#endif
	reloadLibrary(vb_module);

	if (DllCallErroros::NoError != lastError)
	{
		return lastError;
	}
	else
	{
		if (logger.is_open()) logger << "VB LIB: LOADED \n" << std::endl;
	}

	if (DllCallErroros::NoError != (lastError = setPortsArrays(vb_module.module, algIP, algOP)))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: VB: setPortsArrays()\n" << std::endl;
#endif
		return lastError;
	}
	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(vb_module.module, verf2GUIOutMsgs, "set_output_msg")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open())
		{
			logger << "\tERROR: VB: set_output_msg()\n" << std::endl;
		}
#endif
		return lastError;
	}

	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(vb_module.module, algOutMsgs, "set_input_msg_from_CA")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: VB: set_input_msg_from_CA()\n" << std::endl;
#endif
		return lastError;
	}

	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(vb_module.module, sc2VerfOutMsgs, "set_input_msg_from_SC")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: VB: set_input_msg_from_SC()\n" << std::endl;
#endif
		return lastError;
	}
	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(vb_module.module, ver2scOutMsgs, "set_output_msg_to_SC")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: VB: set_output_msg_to_SC()\n" << std::endl;
#endif
		return lastError;
	}

	setStatesArray(vb_module.module, verS);

	if (logger.is_open()) logger << "VB: LOADING COMPLETED SUCCESSFULLY \n" << std::endl;
}

DllCallErroros reloadSCModule()
{

#ifdef TEST_MODE_TRUE
	if (logger.is_open()) logger << "SC: LOAD \n" << std::endl;
#endif
	reloadLibrary(sc_module);

	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(sc_module.module, sc2AlgOutMsgs, "set_output_msg_queue_for_CA")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: SC: set_output_msg_queue_for_CA()\n" << std::endl;
#endif
		return lastError;
	}

	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(sc_module.module, sc2VpOutMsgs, "set_output_msg_queue_for_VP")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: SC: set_output_msg_queue_for_VP()\n" << std::endl;
#endif
		return lastError;
	}

	if (DllCallErroros::NoError != (lastError = setIOMsgsArrays(sc_module.module, sc2VerfOutMsgs, "set_output_msg_queue_for_VB")))
	{
#ifdef TEST_MODE_TRUE
		if (logger.is_open()) logger << "\tERROR: SC: set_output_msg_queue_for_VB()\n" << std::endl;
#endif
		return lastError;
	}

	setStatesArray(sc_module.module, scS);
}