#pragma once
#pragma pack(1)

//#include <stdint.h>
#include "LabVIEWData.h"

#define TEST_MODE_TRUE

//extern struct St_Word;


__declspec(dllexport) int8_t set_input_ports_array(PortsHdl);
__declspec(dllexport) int8_t set_output_ports_array(PortsHdl);

__declspec(dllexport) int8_t set_input_msg(ArrayOfMessagesHdl);
__declspec(dllexport) int8_t set_output_msg(ArrayOfMessagesHdl);
__declspec(dllexport) int8_t set_states_array(ArrayOfStatesHdl);




//__declspec(dllexport) int16_t * get_input_ports_array();
//__declspec(dllexport) int16_t get_input_ports_array_counter();
//__declspec(dllexport) int16_t * get_output_ports_array();
//__declspec(dllexport) int16_t get_output_ports_array_counter();
//__declspec(dllexport) int16_t * get_states_array( void * );


__declspec(dllexport)void LLD();

