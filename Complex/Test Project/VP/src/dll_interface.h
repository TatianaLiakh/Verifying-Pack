#pragma once
#pragma pack(1)

#include "LabVIEWData.h"

#define TEST_MODE_TRUE true
void sayToWholeWorld(char * speach); 

extern "C" __declspec(dllexport) void LLD(PortsHdl algInputPorts, //algInputPorts 
	 PortsHdl algOutputPorts, //algOutputPorts
	 ArrayOfMessagesHdl scenarios2VirtPlantOutputMsgs, //scenarios2VirtPlantOutputMsgs
	 ArrayOfMessagesHdl virtualPlant2GUIOutputMsgs, //algOutputMsgs
	 ArrayOfStatesHdl states_hdl);


/*RESIZE*/

