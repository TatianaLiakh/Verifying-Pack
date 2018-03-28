#include "MakeFullImmitationStep.h"
#include "LV_lib.h"

#define TEST_MODE_TRUE true


LPSTARTUPINFO compiler = nullptr;
LPPROCESS_INFORMATION compiler_info = nullptr;
LPCSTR compilerName = "";
LPTSTR commandLine = "";

//#include <stdio.h> 


DllCallErroros lastError = DllCallErroros::NoError;


std::ofstream logger;

__declspec (dllexport) int32_t init_logger()
{
#ifdef TEST_MODE_TRUE


#endif // TEST_MODE_TRUE

	if (logger.is_open())
	{
		logger.close();
	}
	logger.open("LOG.txt", std::ios::out | std::ios::app);

	
	if (true != logger.is_open())
	{
		FILE * f;
		
		fopen_s(&f, "LOGGER_ERROR.txt", "w");
		fprintf(f, "ACTION");
		fclose(f);
	}
	else
	{

	logger << "LOGGER INITED" << std::endl;
	logger.close();
	}
	return int(logger.is_open()) ;
}

void main()
{
	loadNewDlls();
}


__declspec (dllexport) void setMode(uint8_t mode)
{
	//logger.open("LOG.txt", std::ofstream::out);
#ifdef TEST_MODE_TRUE
	if (true == logger.is_open())
	{
		logger << "SetMode " << (mode == Mode::Auto) << std::endl;
	}

#endif // TEST_MODE_TRUE


	currentMode = static_cast<Mode>(mode);

}

__declspec (dllexport) void freeAllDlls()
{
	freeModule(ca_module);
	freeModule(vp_module);
	freeModule(vb_module);
	freeModule(sc_module);
}

/*Recompile and load all dlls*/
__declspec(dllexport) int32_t loadNewDlls()
{
#ifdef _WIN32

#ifdef TEST_MODE_TRUE
	logger.open("D:/MAIN_LOG.txt", std::ios::out );
	if (logger.is_open()) logger << "loadNewDlls\n" << std::endl;
		
#endif // TEST_MODE_TRUE

	reloadModule(ca_module);
	reloadModule(vp_module);
	reloadModule(vb_module);	
	reloadModule(sc_module);


#ifdef TEST_MODE_TRUE

	if (logger.is_open())
	{
		logger << "loadNewDlls FINISHED\n" << std::endl;
		logger.close();
	}

#endif
	return static_cast<int32_t>(lastError);
	
#endif
	return (lastError = DllCallErroros::SystemIdificationError);
}


__declspec(dllexport) int32_t LLD(
	PortsHdl algInputPorts,
	PortsHdl algOutputPorts,
	///*MsgQueues*/
	ArrayOfMessagesHdl scenarios2AlgOutputMsgs,
	ArrayOfMessagesHdl scenarios2VirtPlantOutputMsgs,
	ArrayOfMessagesHdl scenarios2VerifierOutputMsgs,
	ArrayOfMessagesHdl verifier2scenariousControlOutMsgs,
	/**/
	ArrayOfMessagesHdl algOutputMsgs,
	/**/
	ArrayOfMessagesHdl verifier2GUIOutputMsgs,
	ArrayOfMessagesHdl virtualPlant2GUIOutputMsgs,
	/*StatesArrays*/
	ArrayOfStatesHdl algStates,
	ArrayOfStatesHdl vplantStates,
	ArrayOfStatesHdl verStates,
	ArrayOfStatesHdl scenarioStates
)
{

	if (DllCallErroros::NoError == lastError)
	{
		if (Mode::Auto == currentMode)
			sc_module.mainFunction(verifier2scenariousControlOutMsgs,
				scenarios2AlgOutputMsgs, scenarios2VirtPlantOutputMsgs, scenarios2VerifierOutputMsgs, scenarioStates);
		
		vp_module.mainFunction(algOutputPorts, algInputPorts, scenarios2VirtPlantOutputMsgs, virtualPlant2GUIOutputMsgs, vplantStates);

		ca_module.mainFunction(algInputPorts, algOutputPorts, scenarios2AlgOutputMsgs, algOutputMsgs, algStates);
		
		if (Mode::Auto == currentMode) 
			vb_module.mainFunction(algInputPorts, algOutputPorts, 
				scenarios2VerifierOutputMsgs, algOutputMsgs, 
				verifier2GUIOutputMsgs, verifier2scenariousControlOutMsgs,
				verStates);
	}
	else return lastError;

}
