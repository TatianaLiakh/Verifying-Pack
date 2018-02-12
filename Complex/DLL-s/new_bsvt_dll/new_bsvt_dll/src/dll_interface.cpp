#include "dll_interface.h" 
#include "r_io.h"
#include "R_LIB.H"
#include "bsvtproc.h"
#include "r_main.h" 

extern void Control_Loop(void);  /* for r_main.h */

__declspec(dllexport) int16_t * get_input_ports_array(int16_t * input)
{
	return  reinterpret_cast<int16_t *> ( aInput ) ;
}

__declspec(dllexport) int16_t get_input_ports_array_counter(int16_t * input)
{
	return  static_cast<int16_t> (INPUT_PORTS_COUNTER);
}

__declspec(dllexport) int16_t * get_output_ports_array()
{
	return  reinterpret_cast<int16_t *> ( aOutput );
}

__declspec(dllexport) int16_t get_output_ports_array_counter(int16_t * input)
{
	return  static_cast<int16_t> (OUTPUT_PORTS_COUNTER);
}

__declspec(dllexport) void * get_states_array()
{
	return  reinterpret_cast< void *> (Pr_States);
}

__declspec(dllexport)void LLD()
{
	Control_Loop();
}

