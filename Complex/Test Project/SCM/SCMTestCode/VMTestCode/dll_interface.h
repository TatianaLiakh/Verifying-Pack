#pragma once
#pragma pack(1)

#include "LabVIEWData.h"

#define TEST_MODE_TRUE true
void sayToWholeWorld(char * speach); 

__declspec(dllexport) void LLD(ArrayOfMessagesHdl scenarios2AlgOutputMsgs, //scenarios2AlgOutputMsgs
	ArrayOfMessagesHdl scenarios2VirtPlantOutputMsgs, //scenarios2VirtPlantOutputMsgs
	ArrayOfMessagesHdl scenarios2VerifierOutputMsgs, //scenarios2VerifierOutputMsgs
	ArrayOfStatesHdl states);


