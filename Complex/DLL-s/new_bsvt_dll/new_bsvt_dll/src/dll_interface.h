#pragma once
#pragma pack(1)

#include <stdint.h>


//extern struct St_Word;



__declspec(dllexport) int16_t * get_input_ports_array();
__declspec(dllexport) int16_t get_input_ports_array_counter();
__declspec(dllexport) int16_t * get_output_ports_array();
__declspec(dllexport) int16_t get_output_ports_array_counter();
__declspec(dllexport) int16_t * get_states_array( void * );


__declspec(dllexport)void LLD();

