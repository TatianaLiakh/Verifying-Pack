#include "LabVIEWData.h"

enum Mode
{
	Auto = 0,
	Manual	
};

uint8_t currentMode = Mode::Auto;

__declspec (dllexport) void setMode(uint8_t mode);

__declspec (dllexport) void freeAllDlls(); 

/*Recompile and load all dlls*/
__declspec(dllexport)int32_t loadNewDlls(LStrHandle path);


__declspec(dllexport)int32_t LLD(
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
);

//__declspec (dllexport) int32_t init(
//	PortsHdl algInputPorts,
//	PortsHdl algOutputPorts,
//	///*MsgQueues*/
//	ArrayOfMessagesHdl scenarios2AlgOutputMsgs,
//	ArrayOfMessagesHdl scenarios2VirtPlantOutputMsgs,
//	ArrayOfMessagesHdl scenarios2VerifierOutputMsgs,
//	ArrayOfMessagesHdl algOutputMsgs,
//	/**/
//	ArrayOfMessagesHdl verifier2GUIOutputMsgs,
//	ArrayOfMessagesHdl virtualPlant2GUIOutputMsgs,
//	/*StatesArrays*/
//	ArrayOfStatesHdl algStates,
//	ArrayOfStatesHdl vplantStates,
//	ArrayOfStatesHdl verStates,
//	ArrayOfStatesHdl scenarioStates
//);
