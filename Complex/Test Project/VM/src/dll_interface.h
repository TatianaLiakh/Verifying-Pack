#pragma once
#pragma pack(1)

#include "LabVIEWData.h"

#define TEST_MODE_TRUE true

extern "C" __declspec(dllexport) void LLD(PortsHdl, //algInputPorts 
	PortsHdl, //algOutputPorts
	ArrayOfMessagesHdl, //scenarios2VerifierOutputMsgs
	ArrayOfMessagesHdl, //algOutputMsgs
	ArrayOfMessagesHdl, //verifier2GUIOutputMsgs
	ArrayOfMessagesHdl, //verifier2scenariousControlOutMsgs
	ArrayOfStatesHdl);


/*RESIZE*/



