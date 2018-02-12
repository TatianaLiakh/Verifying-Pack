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

__declspec (dllexport) int32_t init(
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
#ifdef TEST_MODE_TRUE
	//logger.open("LOG.txt", std::ofstream::out);
	if (true == logger.is_open())
	{
		logger << "Initialisation\n" << std::endl;
	}
	
	
#endif // TEST_MODE_TRUE

	algIP = algInputPorts;
	algOP = algOutputPorts;

	sc2AlgOutMsgs = scenarios2AlgOutputMsgs;
	sc2VpOutMsgs = scenarios2VirtPlantOutputMsgs;
	sc2VerfOutMsgs = scenarios2VerifierOutputMsgs;
	ver2scOutMsgs = verifier2scenariousControlOutMsgs;

	algOutMsgs = algOutputMsgs;
	/*Msg2GUI*/
	verf2GUIOutMsgs = verifier2GUIOutputMsgs;
	vp2GUIOutMsgs = virtualPlant2GUIOutputMsgs;
	/*StatesArrays*/
	aS = algStates;
	vpS = vplantStates;
	verS = verStates;
	scS = scenarioStates;

	return lastError; 
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

/*Recompile and load all dlls*/
__declspec(dllexport) int32_t loadNewDlls()
{
#ifdef _WIN32
	//if (!::CreateProcess(compilerName, commandLine, NULL, NULL, NULL, NORMAL_PRIORITY_CLASS, NULL, NULL,
	//	compiler, compiler_info))
	//{
	//	return (lastError = DllCallErroros::CreateProcessError);
	//}
	

#ifdef TEST_MODE_TRUE
	logger.open("D:/LOG.txt", std::ios::out );
	if (logger.is_open()) logger << "loadNewDlls\n" << std::endl;
		
#endif // TEST_MODE_TRUE

	//reloadCAModule();
	//reloadVPModule();
	reloadVBModule();
	//reloadSCModule();


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


__declspec(dllexport) int32_t LLD()
{
	if (DllCallErroros::NoError == lastError)
	{
		//if (Mode::Auto == currentMode)
			//sc();
		
		//vp();
		//ca();
		
		//if (Mode::Auto == currentMode) 
			vb();
	}
	else return lastError;

}
