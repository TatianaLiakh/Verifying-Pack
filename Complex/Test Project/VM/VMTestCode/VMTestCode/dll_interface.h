#pragma once
#pragma pack(1)

#include "LabVIEWData.h"

#define TEST_MODE_TRUE true
void sayToWholeWorld(char * speach); 

__declspec(dllexport) void LLD(PortsHdl, //algInputPorts 
	PortsHdl, //algOutputPorts
	ArrayOfMessagesHdl, //scenarios2VerifierOutputMsgs
	ArrayOfMessagesHdl, //algOutputMsgs
	ArrayOfMessagesHdl, //verifier2GUIOutputMsgs
	ArrayOfMessagesHdl, //verifier2scenariousControlOutMsgs
	ArrayOfStatesHdl);


/*RESIZE*/

//MgErr _states_array_resize(ArrayOfStatesHdl);
//
//MgErr set_input_ports_array(PortsHdl, PortsHdl);
//
//MgErr set_input_msg_from_CA(ArrayOfMessagesHdl);
//MgErr set_input_msg_from_SC(ArrayOfMessagesHdl);
//
//MgErr set_output_msg(ArrayOfMessagesHdl);
//MgErr set_output_msg_to_SC(ArrayOfMessagesHdl);


