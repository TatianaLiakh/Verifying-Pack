#pragma once
#pragma pack(1)

//#include <stdint.h>
#include "LabVIEWData.h"

#define TEST_MODE_TRUE

//extern struct St_Word;


int8_t set_input_ports_array(PortsHdl);
int8_t set_output_ports_array(PortsHdl);

int8_t set_input_msg(ArrayOfMessagesHdl);
int8_t set_output_msg(ArrayOfMessagesHdl);
int8_t set_states_array(ArrayOfStatesHdl);

void parse_input_msg_array(ArrayOfMessagesHdl inputMsgArray);
void parse_output_msg_array(ArrayOfMessagesHdl outputMsgArray);


__declspec(dllexport)void LLD(  PortsHdl, //algInputPorts 
								PortsHdl, //algOutputPorts
								ArrayOfMessagesHdl, //scenarios2VirtPlantOutputMsgs
								ArrayOfMessagesHdl, //virtualPlant2GUIOutputMsgs
								ArrayOfStatesHdl);

