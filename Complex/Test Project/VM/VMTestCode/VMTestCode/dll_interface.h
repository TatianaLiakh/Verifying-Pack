#pragma once
#pragma pack(1)

#include "LabVIEWData.h"

#define TEST_MODE_TRUE true
void sayToWholeWorld(char * speach); 

__declspec(dllexport) void LLD();
__declspec(dllexport) MgErr set_states_array(ArrayOfStatesHdl);

__declspec(dllexport) MgErr set_input_ports_array(PortsHdl);
__declspec(dllexport) MgErr set_output_ports_array(PortsHdl);


__declspec(dllexport) MgErr set_input_msg_from_CA(ArrayOfMessagesHdl);
__declspec(dllexport) MgErr set_input_msg_from_SC(ArrayOfMessagesHdl);

__declspec(dllexport) MgErr set_output_msg(ArrayOfMessagesHdl);
__declspec(dllexport) MgErr set_output_msg_to_SC(ArrayOfMessagesHdl);


